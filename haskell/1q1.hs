-- Ramesh’s basic sal is input through the keyboard.
--  His dearness allowance is 40% of basic sal, and
--   house rent allowance is 20% of basic sal. 
--   Write a program to calculate his gross sal.

main :: IO()

main = do
    salary <- getLine
    let sal = read salary :: Float
    putStrLn "the salary is"
    print sal
    let dearnessAllowance = sal * 0.40
    let houseRent = sal * 0.20
    let grosssal = dearnessAllowance + houseRent + sal
    print grosssal