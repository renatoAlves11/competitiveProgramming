import struct
import sys
input = sys.stdin.read

def hex_para_float(valor_hex):
    valor_int = int(valor_hex, 16)
    return struct.unpack('!f', struct.pack('!I', valor_int))[0]

def float_para_hex(valor_float):
    return format(struct.unpack('!I', struct.pack('!f', valor_float))[0], '08x')

def fma(a, b, c):
    return a * b + c

def nand_bitwise(a, b):
    a_int = struct.unpack('!I', struct.pack('!f', a))[0]
    b_int = struct.unpack('!I', struct.pack('!f', b))[0]
    resultado_nand = ~(a_int & b_int) & 0xFFFFFFFF
    return struct.unpack('!f', struct.pack('!I', resultado_nand))[0]

def processa_entrada():
    data = input().splitlines()
    idx = 0
    T = int(data[idx])
    idx += 1
    resultados = []
    
    for _ in range(T):
        C = [hex_para_float(data[idx].strip())]
        idx += 1
        
        L = int(data[idx].strip())
        idx += 1
        LUT = []
        
        for _ in range(L):
            linha = data[idx].strip().split()
            tamanho = int(linha[0])
            entradas_lut = linha[1:]
            floats_lut = [hex_para_float(h) for h in entradas_lut]
            LUT.append(floats_lut)
            idx += 1

        Q = int(data[idx].strip())
        idx += 1
        
        for _ in range(Q):
            comando = data[idx].strip().split()
            tipo_cmd = comando[0]
            
            if tipo_cmd == 'L':
                i = int(comando[1])
                j = int(comando[2])
                b = int(comando[3])
                mascara = (int(struct.unpack('!I', struct.pack('!f', C[0]))[0]) >> j) & ((1 << b) - 1)
                C.append(LUT[i][mascara])

            elif tipo_cmd == 'N':
                i = int(comando[1])
                j = int(comando[2])
                C.append(nand_bitwise(C[i], C[j]))

            elif tipo_cmd == 'F':
                i = int(comando[1])
                j = int(comando[2])
                k = int(comando[3])
                C.append(fma(C[i], C[j], C[k]))

            elif tipo_cmd == 'C':
                h = comando[1]
                C.append(hex_para_float(h))

            idx += 1

        resultados.append(float_para_hex(C[-1]))
    
    print("\n".join(resultados))

if __name__ == '__main__':
    processa_entrada()
