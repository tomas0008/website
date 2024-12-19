#include <stdio.h>
#include <math.h>

int main()
{
	float strA, strB, strC;
	
	printf("*** Obvod a obsah trojuholnika **\n");
	
	printf("Zadaj stranu a: ");
	scanf("%f", &strA);
	
	printf("Zadaj stranu b: ");
	scanf("%f", &strB);
	
	printf("Zadaj stranu c: ");
	scanf("%f", &strC);
	
	if (strA + strB <= strC)
	{
		printf("Musi platit a + b > c\n");
		printf("Trojuholnik sa neda zostrojit");
	}
	else
	{
		if (strA + strC <= strB)
		{
			printf("Musi platit a + c > b\n");
			printf("Trojuholnik sa neda zostrojit");
		}
		else
		{
			if (strB + strC <= strA)
			{
				printf("Musi platit b + c > a\n");
				printf("Trojuholnik sa neda zostrojit");
			}
			else
			{
				printf("o, O) Obvod trojuholnika\n");
				printf("s, S) Obsah trojuholnika\n");
				printf("Tvoja volba: ");
				getchar();
				
				float obvod = strA + strB + strC;
				
				switch (getchar())
				{
				case 'o':
				case 'O':
					printf("\nObvod trojuholnika: %.2f", obvod);
					break;
					
				case 's':
				case 'S':;
					float s = obvod / 2;
					float obsah = sqrt(s * (s - strA) * (s - strB) * (s - strC));
					printf("\nObsah trojuholnika: %.2f", obsah);
					break;
				
				default:
					printf("Neplatny vstup");
				}
			}
		}
	}
}