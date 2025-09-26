import random
import time
import matplotlib.pyplot as plt

# --- Helper Functions ---

def fill_random(n):
    """Generate random array of size n"""
    return [random.randint(0, 10000) for _ in range(n)]

def copy_array(arr):
    return arr.copy()

# --- Sorting Algorithms with swap count ---

def insertion_sort(arr):
    swaps = 0
    for i in range(1, len(arr)):
        key = arr[i]
        j = i - 1
        while j >= 0 and arr[j] > key:
            arr[j + 1] = arr[j]
            swaps += 1
            j -= 1
        arr[j + 1] = key
    return swaps

def selection_sort(arr):
    swaps = 0
    n = len(arr)
    for i in range(n - 1):
        min_idx = i
        for j in range(i + 1, n):
            if arr[j] < arr[min_idx]:
                min_idx = j
        if min_idx != i:
            arr[i], arr[min_idx] = arr[min_idx], arr[i]
            swaps += 1
    return swaps

def bubble_sort(arr):
    swaps = 0
    n = len(arr)
    for i in range(n - 1):
        for j in range(n - i - 1):
            if arr[j] > arr[j + 1]:
                arr[j], arr[j + 1] = arr[j + 1], arr[j]
                swaps += 1
    return swaps

# --- Main Experiment ---

sizes = [10, 100, 1000, 5000]
insertion_times, selection_times, bubble_times = [], [], []
insertion_swaps, selection_swaps, bubble_swaps = [], [], []

for n in sizes:
    arr = fill_random(n)
    arr1, arr2, arr3 = copy_array(arr), copy_array(arr), copy_array(arr)

    # Insertion Sort
    start = time.time()
    s1 = insertion_sort(arr1)
    end = time.time()
    insertion_times.append(end - start)
    insertion_swaps.append(s1)

    # Selection Sort
    start = time.time()
    s2 = selection_sort(arr2)
    end = time.time()
    selection_times.append(end - start)
    selection_swaps.append(s2)

    # Bubble Sort
    start = time.time()
    s3 = bubble_sort(arr3)
    end = time.time()
    bubble_times.append(end - start)
    bubble_swaps.append(s3)

    print(f"n={n} | Insertion: {insertion_times[-1]:.6f}s, swaps={s1} | "
          f"Selection: {selection_times[-1]:.6f}s, swaps={s2} | "
          f"Bubble: {bubble_times[-1]:.6f}s, swaps={s3}")

# --- Plotting Results ---

plt.figure(figsize=(10, 6))

# Plot times
plt.plot(sizes, insertion_times, marker='o', label="Insertion Sort")
plt.plot(sizes, selection_times, marker='s', label="Selection Sort")
plt.plot(sizes, bubble_times, marker='^', label="Bubble Sort")

plt.xlabel("Input Size (n)")
plt.ylabel("Execution Time (seconds)")
plt.title("Comparison of Sorting Algorithms (Execution Time)")
plt.legend()
plt.grid(True)
plt.show()
