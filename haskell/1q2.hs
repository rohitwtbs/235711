-- The distance between two cities (in km.) is input through the keyboard.
--  Write a program to convert and print this distance in meters, feet, inches and centimeters.


main :: IO()

main = do
    putStrLn "enter the distance in km"
    dist <- getLine
    let distance = read dist :: Float
    let distanceInMetres = distance * 1000
    putStrLn " the converted distance is" 
    print distanceInMetres

