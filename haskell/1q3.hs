-- If the marks obtained by a student in five different subjects are input through the keyboard,
--  find out the aggregate marks and percentage marks obtained by the student.
--   Assume that the maximum marks that can be obtained by a student in each subject is 100.

import Control.Monad
main :: IO()

-- main = do
--     putStrLn "enter the marks"



main = do
    let list = []
    let a = 0
  line <- getLine
  unless (line == "q") $ do
    -- process line
    putStrLn "this is number"
    a = read line :: Integer
    a: []
    main
