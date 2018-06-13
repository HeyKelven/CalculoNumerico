!gfortran PageRank.f95 -o main

PROGRAM PageRank
    implicit none
    double precision, dimension(4, 4) :: A
    double precision, dimension(:), allocatable :: V

    A(1,1) = 0
    A(1,2) = 0
    A(1,3) = 1
    A(1,4) = 1/2.0

    A(2,1) = 1/3.0
    A(2,2) = 0
    A(2,3) = 0
    A(2,4) = 0

    A(3,1) = 1/3.0
    A(3,2) = 1/2.0
    A(3,3) = 0
    A(3,4) = 1/2.0

    A(4,1) = 1/3.0
    A(4,2) = 1/2.0
    A(4,3) = 0
    A(4,4) = 0

    !print *, A

    V = calcPageRank(A)

    print *, V

    contains
    function calcPageRank(A)
        double precision, dimension(:, :) :: A
        real :: x, m
        integer :: n, i, j, counter
        double precision, dimension (:), allocatable :: calcPageRank, sm
        double precision :: before, precision

        !m padrao google
        m = 0.15

        !setando before como 1 para entrar no looping e setando precision
        before = 1
        precision = 0.0005
        counter = 0

        !obtendo n da matriz n x n, e alocando no vetor de pesos
        x = size(A)
        n = sqrt(x)
        allocate(calcPageRank(n))
        allocate(sm(n))

        !multiplicando a matriz A pelo (1-m)
        do i = 1, n
            do j = 1, n
                A(i,j) = A(i,j) * (1-m)
            enddo
        enddo

        !criando os vetores de pesos
        do i = 1, n
            calcPageRank(i) = 1.0/n
            sm(i) = (1.0/n) * m
        enddo

        !formula iterativa pra calcular pesos ate a precisao desejada
        do while(abs(before - calcPageRank(1)) > precision )
            !pegando o primeiro valor antigo do vetor pesos para calcular a precisao pos loop
            before = calcPageRank(1)


            !multiplicando matriz (1-m)Ay
            calcPageRank = MATMUL(A, calcPageRank)

            !somando (1-m)Ay + sm
            do j = 1, n
                calcPageRank(j) = calcPageRank(j) + sm(j)
            enddo
            !counter para contar numero de iteracoes
            counter = counter + 1
        enddo

        !print*, "total de iteracoes na formula: ", counter

    end function

END PROGRAM PageRank