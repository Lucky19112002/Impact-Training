import itertools 
def parcel_problem(n, k, weights):
  """
  Solves the parcel problem.

  Args:
    n: The number of boxes.
    k: The position of the Head Post Master's office.
    weights: The weights of the boxes.

  Returns:
    The minimum total effort taken to get the boxes in sorted order and the heaviest in position k.
  """

  # Create a list of pairs of the weights and indices of the boxes.
  boxes = [(weights[i], i) for i in range(n)]

  # Sort the boxes in increasing order of weight.
  boxes.sort()

  # Initialize the minimum total effort to infinity.
  min_effort = float("inf")

  # Iterate over all possible permutations of the boxes.
  for permutation in itertools.permutations(boxes):
    # Calculate the total effort for the current permutation.
    effort = 0
    for i in range(n - 1):
      effort += permutation[i][0] * permutation[i + 1][0]

    # Update the minimum total effort if necessary.
    if effort < min_effort:
      min_effort = effort

  # Return the minimum total effort.
  return min_effort

print(parcel_problem(5,2,[20,50,30,80,70]))
