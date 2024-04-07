# Define a class to represent whole numbers
class WholeNum:
    # Initialize the value of the whole number
    def _init_(self, value):
        # Check if the value is a non-negative integer
        if isinstance(value, int) and value >= 0:
            self.value = value
        else:
            raise ValueError("Invalid value for WholeNum")

    # Define a method to return the whole number zero
    @staticmethod
    def zero():
        return WholeNum(0)

    # Define a method to check if a whole number is zero
    def isZero(self):
        return self.value == 0

    # Define a method to add two whole numbers
    def add(self, other):
        # Check if the other value is a WholeNum
        if isinstance(other, WholeNum):
            # Return a new WholeNum with the sum of the values
            return WholeNum(self.value + other.value)
        else:
            raise TypeError("Invalid type for WholeNum addition")

    # Define a method to check if two whole numbers are equal
    def isEqual(self, other):
        # Check if the other value is a WholeNum
        if isinstance(other, WholeNum):
            # Return a boolean indicating the equality of the values
            return self.value == other.value
        else:
            raise TypeError("Invalid type for WholeNum comparison")

    # Define a method to return the successor of a whole number
    def successor(self):
        # Return a new WholeNum with the value incremented by one
        return WholeNum(self.value + 1)

    # Define a method to subtract two whole numbers
    def subtract(self, other):
        # Check if the other value is a WholeNum
        if isinstance(other, WholeNum):
            # Return a new WholeNum with the difference of the values
            # If the difference is negative, return zero instead
            return WholeNum(max(self.value - other.value, 0))
        else:
            raise TypeError("Invalid type for WholeNum subtraction")

    # Define a method to represent the whole number as a string
    def _str_(self):
        return str(self.value)