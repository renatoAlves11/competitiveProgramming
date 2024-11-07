def maximizarNumero(n, k):
    n = list(str(n))
    maxNum = [''.join(n)]

    def retroceder(num, trocas):
        if trocas == 0:
            return
        
        n_len = len(num)
        
        for i in range(n_len):
            max_digito = max(num[i:])
            
            if num[i] == max_digito:
                continue

            for j in range(n_len - 1, i, -1):
                if num[j] == max_digito:
                    # Perform the swap
                    num[i], num[j] = num[j], num[i]
                    currentNum = ''.join(num)
                    
                    if currentNum > maxNum[0]:
                        maxNum[0] = currentNum

                    retroceder(num, trocas - 1)

                    num[i], num[j] = num[j], num[i]
                    break

    retroceder(n, k)
    return int(maxNum[0])

def coletaValores():
    return map(int, input().split())

def main():
    N, K = coletaValores()
    print(maximizarNumero(N, K))

if __name__ == "__main__":
    main()
