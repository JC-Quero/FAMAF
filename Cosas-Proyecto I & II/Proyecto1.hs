{-# LANGUAGE NPlusKPatterns #-}

-- Ejercicios 1
--a) 
esCero :: Int -> Bool
esCero x = x == 0 

-- Ejemplo 1 
--ghci> esCero 3
--False

--Ejemplo 2
--ghci> esCero 0
--True

--b)
esPositivo :: Int -> Bool
esPositivo x = (x > 0)

-- Ejemplo 1
--ghci> esPositivo 3
--True

--Ejemplo 2
--ghci> esPositivo (-4)
--False

--c)
esVocal :: Char -> Bool
esVocal x = x `elem` "aeiou"

--Ejemplo 1
--ghci> esVocal 'a'
--True

--Ejemplo 2
--ghci> esVocal 'v'
--False

--d)
valorAbsoluto :: Int -> Int
valorAbsoluto x
    | x >= 0    = x
    | otherwise = -x

--Ejemplo 1
--ghci> valorAbsoluto 1
--1

--Ejemplo 2
--ghci> valorAbsoluto (-6)
--6


--2
--a)
paratodo :: [Bool] -> Bool
paratodo[] = True
paratodo (x:xs) = x && paratodo xs

--Ejemplo 1 
--ghci> paratodo [True,True,True]
--True

--Ejemplo 2
--ghci> paratodo [True,False,True]
--False

--b)
sumatoria:: [Int] -> Int
sumatoria[] = 0
sumatoria (x:xs) = x + sumatoria xs

--Ejemplo 1
--ghci> sumatoria [1,2,3]
--6

--Ejemplo 2
--ghci> sumatoria [50,50]
--100

--c)
productoria:: [Int] -> Int
productoria[] = 1
productoria(x:xs) = x * productoria xs

--Ejemplo 1 
--ghci> productoria [2,2]
--4

--Ejemplo 2
--ghci> productoria [4,2]
--8

--d)
factorial:: Int -> Int
factorial 0 = 1
factorial n = n * factorial (n-1)

--Ejemplo 1
--ghci> factorial 4
--24

--Ejemplo 2
--ghci> factorial 3
--6

--e)
promedio :: [Int] -> Int
promedio[]= 0
promedio xs = sumatoria xs `div` length xs

--Ejemplo 1
--ghci> promedio [2,4]
--3

--Ejemplo 2
--ghci> promedio [5,5,5]
--5

--3
pertenece:: Int -> [Int] -> Bool
pertenece n [] = False
pertenece n (x:xs) | n==x = True
                   | otherwise = pertenece n xs

--Ejemplo 1
--ghci> pertenece 4 [2,4,6]
--True

--Ejemplo 2
--pertenece 7 [2,4,6]
--False

--4)
--a)
paratodo' :: [a] -> (a -> Bool) -> Bool
paratodo' [] _ = True
paratodo' (x:xs) pred = pred x && paratodo' xs pred

--Ejemplo 1
--ghci> paratodo' [3,4,5] esPositivo
--True

--Ejemplo 2
--ghci> paratodo' [1,(-5),6] esPositivo
--False

--b)
existe':: [a] -> (a -> Bool)  -> Bool
existe' [] _ = False
existe' (x:xs) pred = pred x || existe' xs pred

--Ejemplo 1
--ghci> existe' "tnt" esVocal
--False

--Ejemplo 2 
--ghci> existe' "Hola" esVocal
--True

--c)
sumatoria' :: [a] -> (a  -> Int) -> Int
sumatoria' [] _ = 0
sumatoria' (x:xs) pred = pred x + sumatoria' xs pred

--Ejemplo 1
--ghci> sumatoria' [2,3] factorial
--8

--Ejemplo 2
--ghci> sumatoria' [2,2] factorial
--4

--d)
productoria'  :: [a] -> (a -> Int) -> Int
productoria'[] _  = 1
productoria' (x:xs) pred = pred x * productoria' xs pred

--Ejemplo 1
--ghci> productoria' [2,3] valorAbsoluto
--6

--Ejemplo 2
--ghci> productoria' [(-4),(-2)] valorAbsoluto
--8


--5)
paratodo'' :: [Bool] -> Bool
paratodo'' xs = paratodo' xs id

--Ejemplo 1
--hci> paratodo'' [True,False,True]
--False

--Ejemplo 2
--ghci> paratodo'' [True,True,True]
--True

--6)

--a)
todosPares :: [Int] -> Bool
todosPares xs = paratodo' xs even

--Ejemplo 1
--todosPares [2,3,4]
--False

--Ejemplo 2
--ghci> todosPares [2,2,8]
--True

--b)

--Definimos la funcion esMultiploDe de un numero n y otro m.
esMultiploDe :: Int -> Int -> Bool
esMultiploDe n x = x `mod` n == 0

hayMultiplo :: Int -> [Int] -> Bool
hayMultiplo n xs = existe' xs (esMultiploDe n)

--Ejemplo 1
--ghci> hayMultiplo 3 [5,6,1]
--True

--Ejemplo 2
--ghci> hayMultiplo 3 [5,7,8]
--False

--c)
sumaCuadrados :: Int -> Int
sumaCuadrados n = sumatoria' [i^2 | i <- [0..n-1]] id

--Ejemplo 1
--ghci> sumaCuadrados 5
--30

--Ejemplo 2
--ghci> sumaCuadrados 3
--5

--d)
existeDivisor :: Int -> [Int] -> Bool
existeDivisor n ls = any (\x -> n `mod` x == 0) ls


--Ejemplo 1
--ghci> existeDivisor 6 [2,3,4,5]
--True

--Ejemplo 2 
--ghci> existeDivisor 7 [2,3,4,5,6]
--False


--e)
esPrimo :: Int -> Bool
esPrimo n = n > 1 && not (existeDivisor n [2..(n-1)])

--Ejemplo 1
--ghci> esPrimo 13
--True

--Ejemplo 2
--ghci> esPrimo 6
--False

--f)
factorial' :: Int -> Int
factorial' n = productoria' [1..n] id

--Ejemplo 1
--ghci> factorial' 3
--6

--Ejemplo 2
--ghci> factorial' 4
--24


--7) Sobre la funcion map y filter
    --Que hace la funcion filter?   
        -- filter :: (a -> Bool) -> [a] -> [a] toma una función y una lista, y devuelve una nueva lista donde cada elemento es 
        --el resultado de aplicar esa función a cada elemento de la lista original.   

    --Que hace la funcion map?
        -- map :: (a -> b) -> [a] -> [b]  toma una función y una lista, y devuelve una nueva lista 
        --donde cada elemento es el resultado de aplicar esa función a cada elemento de la lista original.

    --A que equivale la expresion map succ [1, -4, 6, 2, -8], donde succ n = n+1    
        -- Equivale a esto [2,-3,7,3,-7]

    --Y la expresion filter esPositivo [1, -4, 6, 2, -8]    
        --[1,6,2]

--8)
--a) 
duplicaRec:: [Int] -> [Int]
duplicaRec[] = []
duplicaRec(x:xs)= x *2  : duplicaRec xs

--Ejemplo 1
--ghci> duplicaRec [2,3,4]
--[4,6,8]

--Ejemplo 2
-- ghci> duplicaRec [2,6,8]
--[4,12,16]

--b)
duplicaMap:: [Int]->[Int]
duplicaMap xs = map (*2) xs

--Ejemplo 1
--ghci> duplicaMap [2,3,4]
--[4,6,8]

--Ejemplo 2
-- ghci> duplicaRec [2,6,8]
--[4,12,16]

--9
--a)
listaDePrimos :: [Int] -> (Int -> Bool) -> [Int]
listaDePrimos [] _ = []
listaDePrimos (x:xs) esPrimo
    | esPrimo x = x : listaDePrimos xs esPrimo
    | otherwise = listaDePrimos xs esPrimo

--Ejemplo 1
--ghci> listaDePrimos [3,4,5,6,7] esPrimo
--[3,5,7]

--Ejemplo 2
--listaDePrimos [13,7,2,4,7] esPrimo
--[13,7,2,7]

--b)

listaDePrimos' :: [Int] -> (Int -> Bool) -> [Int]
listaDePrimos' xs esPrimo = filter esPrimo xs

--Ejemplo 1
--ghci> listaDePrimos [3,4,5,6,7] esPrimo
--[3,5,7]

--Ejemplo 2
--listaDePrimos [13,7,2,4,7] esPrimo
--[13,7,2,7]

--c)

multiplicaPrimos' :: [Int] -> Int
multiplicaPrimos' xs = productoria' (filter esPrimo xs) id

--Ejemplo 1 
--ghci> multiplicaPrimos'[3,3,6,8]
--9

--Ejemplo 2
--ghci> multiplicaPrimos' [2,3,6,12,24]
--6

primIgualesA :: Eq a => a -> [a] -> [a]
primIgualesA _ [] = []  
primIgualesA pred (x:xs)
    | pred == x = x : primIgualesA pred xs 
    | otherwise = []  

--Ejemplo 1
--ghci> primIgualesA 'a' "aaaaab"
-- "aaaaa"

--Ejemplo 2
--ghci> primIgualesA 3 [3,1,2,5]
--[3]

primIgualesA' :: Eq a => a -> [a] -> [a]
primIgualesA' pred xs = takeWhile (== pred) xs

--Ejemplo 1
--ghci> primIgualesA' 3 [4,2,3,3]
--[]

--Ejemplo 2
--ghci> primIgualesA' 6 [6,6,6,6,5]
--[6,6,6,6]

--11) 
--a)
primIguales :: Eq a => [a] -> [a]
primIguales [] = [] 
primIguales [x] = [x] 
primIguales (x:y:xs)
    | x == y = x : primIguales (y:xs) 
    | otherwise = [x] 

--Ejemplo 1
--ghci> primIguales [3,3,4,1]
--[3,3]

--Ejemplo 2
--ghci> primIguales "eeeeeafd"
--"eeeee"

--b)
primIguales' :: Eq a => [a] -> [a]
primIguales' [] = []  
primIguales' xs = primIgualesA (xs !! 0) xs 

--Ejemplo 1
--ghci> primIguales' [3,3,4,1]
--[3,3]

--Ejemplo 2
--ghci> primIguales "eeeeeafd"
--"eeeee"