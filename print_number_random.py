import random

# Generate 5 random numbers between 1 and 100
random_numbers = random.sample(range(0, 30000), 500)

# Print the random numbers without comma
print(*random_numbers)

