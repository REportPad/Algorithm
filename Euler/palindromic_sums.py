def is_palindrome(n):
    """Check if a number is palindromic."""
    s = str(n)
    return s == s[::-1]

def palindromic_sums(N):
    """
    Find all palindromic numbers less than N that can be expressed as sums of consecutive squares.
    """
    M = int(pow(N, 0.5))  # Upper limit for the square root
    palindromic_numbers = set()
    
    for i in range(1, M):
        current_sum = i * i
        for j in range(i + 1, M):
            current_sum += j * j
            if current_sum >= N:
                break
            if is_palindrome(current_sum):
                palindromic_numbers.add(current_sum)
    
    return palindromic_numbers

# Solve for N = 10^8
N = 10**8
result_set = palindromic_sums(N)
print("Sum of all palindromic numbers:", sum(result_set))
