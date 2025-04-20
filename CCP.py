import math
import os
import sympy as sp

def show_menu():
    print("=== Recurrence Relation Solver ===")
    print("Choose the type of recurrence to solve:")
    print("1. Divide and Conquer (T(n) = aT(n/b) + f(n))")
    print("2. Decrease and Conquer (T(n) = T(n - k) + f(n))")
    print("3. Linear Homogeneous (e.g., T(n) = aT(n-1) + bT(n-2))")
    print("4. Linear Non-Homogeneous (e.g., T(n) = aT(n-1) + f(n))")
    print("5. Multiple Recurrence (e.g., T(n) = T(n-1) + T(n-3))")
    print("6. Nonlinear Recurrence (e.g., T(n) = T(n-1)^2 + 1)")
    print("0. Exit")

def get_user_choice():
    while True:
        try:
            choice = int(input("Enter your choice (0-6): "))
            if 0 <= choice <= 6:
                return choice
            else:
                print("❌ Invalid choice. Please enter a number from 0 to 6.")
        except ValueError:
            print("❌ Invalid input. Please enter a number.")


def master_theorem_solver():
    print("\n--- Master Theorem Solver ---")
    try:
        a = int(input("Enter value of a (number of subproblems): "))
        b = int(input("Enter value of b (factor the problem size is divided by): "))
        f_str = input("Enter f(n) (e.g., n, n^2, n log n): ").lower().replace(" ", "")

        # Estimate d from f(n) like n, n^2, n^3, nlogn, etc.
        if "log" in f_str:
            if "^" in f_str:
                d = float(f_str.split("^")[1].split("log")[0])
                log_part = "log n"
            else:
                d = 0
                log_part = "log n"
        elif "^" in f_str:
            d = float(f_str.split("^")[1])
            log_part = ""
        elif f_str == "n":
            d = 1
            log_part = ""
        elif f_str == "1":
            d = 0
            log_part = ""
        else:
            print("❌ Unsupported or unclear f(n) format.")
            return

        log_b_a = math.log(a, b)

        print(f"\nAnalyzing T(n) = {a}T(n/{b}) + f(n) where f(n) = {f_str}")
        print(f"Computed: log_b(a) = log_{b}({a}) = {log_b_a:.2f}, d = {d}")

        # Master Theorem Decision
        if d < log_b_a:
            print("=> Case 1 applies: f(n) is polynomially smaller than n^log_b(a)")
            print("=> T(n) = Θ(n^{:.2f})".format(log_b_a))
        elif d == log_b_a:
            print("=> Case 2 applies: f(n) = Θ(n^log_b(a))")
            if log_part:
                print("=> T(n) = Θ(n^{:.2f} log n)".format(d))
            else:
                print("=> T(n) = Θ(n^{:.2f} log n)".format(d))
        else:
            print("=> Case 3 applies: f(n) is polynomially larger than n^log_b(a)")
            print("=> T(n) = Θ(f(n)) = Θ({})".format(f_str))

    except Exception as e:
        print("❌ Error:", str(e))

def recursion_tree_solver():
    print("\n--- Recursion Tree Solver for Decrease and Conquer ---")
    try:
        k = int(input("Enter value of k (decrease by k): "))
        f_str = input("Enter f(n) (e.g., 1, n, n^2): ").lower().replace(" ", "")

        # Estimate function growth
        if f_str == "1":
            growth = "Θ(n)"
            explanation = "Each level costs 1, total levels = n/k ⇒ Θ(n)"
        elif f_str == "n":
            growth = "Θ(n^2)"
            explanation = "Costs: n + (n-1) + ... + 1 ⇒ Arithmetic Series ⇒ Θ(n²)"
        elif "^" in f_str:
            d = float(f_str.split("^")[1])
            growth = f"Θ(n^{d + 1})"
            explanation = f"Summing n^{d} over n levels ⇒ Θ(n^{d + 1})"
        else:
            print("❌ Unsupported or unclear f(n) format.")
            return

        print(f"\nAnalyzing T(n) = T(n - {k}) + f(n), where f(n) = {f_str}")
        print(f"Using Recursion Tree with {k}-step decrease")
        print(f"=> Estimated Time Complexity: {growth}")
        print(f"=> Reasoning: {explanation}")

    except Exception as e:
        print("❌ Error:", str(e))

def linear_homogeneous_solver():
    print("\n--- Linear Homogeneous Recurrence Solver ---")
    try:
        n = int(input("Enter the order of recurrence (e.g., 2 for T(n) = aT(n-1) + bT(n-2)): "))
        coeffs = []

        print("Enter coefficients a₁, a₂, ..., aₙ for: T(n) = a₁·T(n-1) + a₂·T(n-2) + ...")
        for i in range(1, n+1):
            c = int(input(f"Coefficient a{i}: "))
            coeffs.append(c)

        # Create the characteristic equation
        r = sp.symbols('r')
        poly = r**n - sum(coeffs[i] * r**(n - i - 1) for i in range(n))

        print(f"\nCharacteristic Equation: {poly} = 0")

        # Solve the equation for roots
        roots = sp.solve(poly, r)
        roots_sorted = sorted(roots, key=lambda x: abs(sp.N(x)), reverse=True)

        print(f"Roots: {roots}")
        dominant_root = roots_sorted[0]
        abs_root_val = abs(sp.N(dominant_root))

        print(f"\nDominant Root (by magnitude): {dominant_root} ≈ {abs_root_val:.4f}")
        print(f"✅ Time Complexity: Θ({abs_root_val:.4f}ⁿ)")

    except Exception as e:
        print("❌ Error:", str(e))

def linear_nonhomogeneous_solver():
    print("\n--- Linear Non-Homogeneous Recurrence Solver ---")
    try:
        n = int(input("Enter the order of recurrence: "))
        coeffs = []
        print("Enter coefficients a₁ to aₙ for: T(n) = a₁·T(n-1) + ... + aₙ·T(n-k) + f(n)")

        for i in range(1, n+1):
            c = int(input(f"Coefficient a{i}: "))
            coeffs.append(c)

        f_str = input("Enter f(n) (e.g. 1, n, 2^n): ").replace(" ", "").lower()

        # Solve homogeneous part
        r = sp.symbols('r')
        poly = r**n - sum(coeffs[i] * r**(n - i - 1) for i in range(n))
        roots = sp.solve(poly, r)
        roots_sorted = sorted(roots, key=lambda x: abs(sp.N(x)), reverse=True)
        dominant_root = abs(sp.N(roots_sorted[0]))

        # Determine f(n) class and growth rate
        f_growth = 0
        if f_str == "1":
            f_class = "constant ⇒ Tₚ(n) = A"
            f_growth = 1  # Θ(1)
        elif f_str == "n":
            f_class = "linear ⇒ Tₚ(n) = An + B"
            f_growth = 1.0001  # Slightly more than constant to compare
        elif "^" in f_str and f_str[0].isdigit():
            base = float(f_str.split("^")[0])
            f_class = f"exponential ⇒ Tₚ(n) = A·{base}ⁿ"
            f_growth = base
        else:
            print("❌ Unsupported f(n) format for this solver.")
            return

        final_growth = max(dominant_root, f_growth)

        print(f"\nHomogeneous Characteristic Equation: {poly} = 0")
        print(f"Roots: {roots}")
        print(f"Dominant Root (Homogeneous): {dominant_root:.4f}")
        print(f"f(n): {f_str} → {f_class}")
        print(f"\n✅ Final Time Complexity: Θ({final_growth:.4f}ⁿ)")

    except Exception as e:
        print("❌ Error:", str(e))

def count_custom_calls(n, a, b, memo=None):
    if memo is None:
        memo = {}
    if n <= 0:
        return 1
    if n in memo:
        return memo[n]
    memo[n] = count_custom_calls(n - a, a, b, memo) + count_custom_calls(n - b, a, b, memo)
    return memo[n]

def multiple_custom_recursive_solver():
    print("\n--- General Multiple Recursive Calls Solver ---")
    print("Solves recurrence: T(n) = T(n - a) + T(n - b)")
    
    try:
        n = int(input("Enter a value for n (e.g., 10 to 50): "))
        a = int(input("Enter a (positive integer): "))
        b = int(input("Enter b (positive integer): "))

        if a <= 0 or b <= 0:
            print("❌ 'a' and 'b' must be positive integers.")
            return

        calls = count_custom_calls(n, a, b)
        prev_calls = count_custom_calls(n - 1, a, b)
        growth_rate = calls / prev_calls if prev_calls != 0 else 1

        print(f"\n🔢 Total Recursive Calls at T({n}) ≈ {calls}")
        print(f"📈 Estimated Growth Rate: {growth_rate:.4f}")
        print(f"✅ Estimated Time Complexity: Θ({growth_rate:.2f}ⁿ)")

    except Exception as e:
        print("❌ Error:", str(e))

def general_nonlinear_solver():
    print("\n--- General Nonlinear Recurrence Solver ---")
    print("Input format examples:")
    print(" - Recurrence: T[n-1]**2 + 1")
    print(" - Base case(s): T[0]=1 or T[0]=1, T[1]=2")

    try:
        formula = input("Enter recurrence formula for T[n] in terms of T[n-k] and n: ").strip()
        base_cases_input = input("Enter base cases (e.g., T[0]=1, T[1]=2): ").strip()
        max_n = int(input("Solve up to T[n], enter value for n: "))

        # Parse base cases
        T = {}
        for case in base_cases_input.split(","):
            left, right = case.strip().split("=")
            index = int(left[left.find("[") + 1:left.find("]")])
            T[index] = eval(right.strip())

        # Compute recurrence
        for i in range(max(T.keys()) + 1, max_n + 1):
            T[i] = eval(formula, {"T": T, "n": i})
            print(f"T({i}) = {T[i]}")

        growth_rate = T[max_n] / T[max_n - 1] if T.get(max_n - 1) else None
        if growth_rate:
            print(f"\n📈 Approx. Growth Rate: {growth_rate:.2f}")
        else:
            print("\n⚠️ Could not estimate growth rate.")

        # Estimate growth class
        if T[max_n] > 10**6:
            print("✅ Estimated Time Complexity: Super-Exponential (possibly Θ(2^(2^n)))")
        elif growth_rate and growth_rate > 5:
            print("✅ Estimated Time Complexity: Exponential")
        elif growth_rate and growth_rate > 1:
            print("✅ Estimated Time Complexity: Polynomial or Super-Polynomial")
        else:
            print("✅ Estimated Time Complexity: Logarithmic or Constant")

    except Exception as e:
        print("❌ Error:", str(e))








def main():
    while True:
        show_menu()
        choice = get_user_choice()

        if choice == 0:
            os.system('cls')
            print("👋 Exiting Recurrence Solver. Goodbye!")
            break
        elif choice == 1:
            os.system('cls')
            print("➡ Solving Divide and Conquer recurrence...")
            master_theorem_solver()
        elif choice == 2:
            os.system('cls')
            print("➡ Solving Decrease and Conquer recurrence...")
            recursion_tree_solver()
        elif choice == 3:
            os.system('cls')
            print("➡ Solving Linear Homogeneous recurrence...")
            linear_homogeneous_solver()
        elif choice == 4:
            os.system('cls')
            print("➡ Solving Linear Non-Homogeneous recurrence...")
            linear_nonhomogeneous_solver()
        elif choice == 5:
            os.system('cls')
            print("➡ Solving Multiple Recurrence...")
            multiple_custom_recursive_solver()
        elif choice == 6:
            os.system('cls')
            print("➡ Solving Nonlinear Recurrence...")
            general_nonlinear_solver()
        print("\n")
        print("=====================================\n")
        input("Press Enter to continue...")
        os.system('cls')
        
        

if __name__ == "__main__":
    main()
