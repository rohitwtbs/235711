main :: IO()
main = do
    putStrLn (greet "who")
    putStrLn (greet "1")
    let list = [1,2,3,4,5]
    putStrLn ( elementAt list 2)

greet "who" = "hello" ++ "who"

greet  "1" = "1"