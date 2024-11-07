import java.util.Scanner;
import java.util.ArrayList;

public class A {
  public static void main(String[] args) {
    Scanner scLine = new Scanner(System.in);
    Scanner scInt = new Scanner(System.in);
    int tamanho = scInt.nextInt(), soma = 0;
    String entrada = scLine.nextLine();
    String [] entradaSplit = entrada.split("b");
    for (int i = 0; i < entradaSplit.length; i++) {
    	 System.out.println(entradaSplit[i]);
      if (entradaSplit[i].length() > 1) {
        soma += entradaSplit[i].length();
      }
    }
    System.out.println(soma);
  }
}