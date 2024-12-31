import math

def is_pandigital_9(num):
    """Check if a number is 1-9 pandigital."""
    return len(str(num)) == 9 and set(str(num)) == set('123456789')

def first_9_digits_of_fibonacci(n):
    """Calculate the first 9 digits of the nth Fibonacci number."""
    phi = (1 + math.sqrt(5)) / 2
    log_fib = n * math.log10(phi) - math.log10(math.sqrt(5))
    fractional_part = log_fib - int(log_fib)
    first_9_digits = int(10**(fractional_part + 8))  # +8 ensures 9 digits
    return first_9_digits

def find_pandigital_fibonacci():
    """Find the first Fibonacci number where both first and last 9 digits are pandigital."""
    mod = 10**9
    a, b = 1, 1
    n = 2
    
    while True:
        a, b = b, (a + b) % mod
        n += 1
        
        # Check last 9 digits
        if is_pandigital_9(b):
            # Check first 9 digits
            first_digits = first_9_digits_of_fibonacci(n)
            if is_pandigital_9(first_digits):
                return n

# Find the result
result = find_pandigital_fibonacci()
print(f"The first Fibonacci number where both the first and last 9 digits are pandigital is F_{result}.")
