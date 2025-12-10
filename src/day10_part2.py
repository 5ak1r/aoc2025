from pulp import LpProblem, LpMinimize, LpVariable, lpSum, LpInteger, PULP_CBC_CMD

def remove_brackets(string):
  return ''.join(filter(lambda x: x not in "()\{\}[]", string))

def solution():
  total = 0
  
  with open("inputs/day10.txt", "r") as file:
    for line in file:
      line = line.split()
      filtered = [remove_brackets(l) for l in line]

      buttons = [[int(i) for i in f.split(',')] for f in filtered[1:-1]]
      joltages = [int(i) for i in filtered[-1].split(',')]

      buttons_len = len(buttons)
      joltages_len = len(joltages)

      # x[i] = how many times button i is pressed, lowbound=0 due to non-negative button presses, cat ensures answer is integer (unlike scipy)
      variables = [LpVariable(f"x{i}", lowBound=0, cat=LpInteger) for i in range(buttons_len)]

      # minimisation problem, minimise the sum of the variables (total presses)
      prob = LpProblem("name", LpMinimize)
      prob += lpSum(variables)

      # generate constraints
      for j in range(joltages_len):
        prob += lpSum(variables[x] for x in range(buttons_len) if j in buttons[x]) == joltages[j]

      solver = PULP_CBC_CMD(msg=False)
      prob.solve(solver)

      total += sum(var.varValue for var in variables)
  
  return int(total)




if __name__ == "__main__":
  print(f"Part Two: {solution()}")
