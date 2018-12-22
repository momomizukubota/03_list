#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void trim(char* str)
{
	char *p;
	p = strchr(str, '\n');
	if (p != NULL) {
		*p = '\0';
	}
}

char* retComma(char* string)
{
	char *p;
	p = strchr(string, ',');
	if (p != NULL) {
		//�J���}������|�C���^��ԋp
		return p;
	}
	//�J���}�܂܂�ĂȂ��ꍇ�͕�����擪�|�C���^��ԋp
	return string;
}

char* subString(char* string, int val, char* retStr)
{
	char *rsp = retStr;
	char *sp = string;

	for (int i = 0; i < val; i++)
	{
		*rsp++ = *sp++;
	}

	return retStr;
}

int main(int argc, char *argv[])
{
	static const int TOTAL_LINE = 100;

	char str[5];

	char string[sizeof(str) * TOTAL_LINE] = "";
	char buffer[sizeof(str) * TOTAL_LINE] = "";

	string[0] = '\0';
	while (fgets(str, sizeof(str), stdin)) {

		//���ݕ\��
		if (atoi(str) == 0)
		{
			printf("%s\n", string);
		}
		//�擪�폜(�폜�����ۂɏ��������̂�ꂭ)
		else if (atoi(str) == -1)
		{
			//�J���}���܂܂�Ă��Ȃ������ꍇ�͐擪��\0
			char *rp = retComma(string);
			if (string == rp)
			{
				printf("%s\n", string);
				string[0] = '\0';
			}
			//�ȊO�̏ꍇ�̓J���}�ȍ~��string�փR�s�[����
			else
			{
				char s[5] = "";
				printf("%s\n", subString(string, (unsigned)(rp - string), s));
				strcpy_s(string, ++rp);
			}


		}
		//�擪�ɒǉ�
		else
		{
			trim(str);
			//�����񂪋󂶂�Ȃ��Ƃ��� str, ��ǉ�����
			if (string[0] != '\0')
			{
				strcpy_s(buffer, str);
				strcat_s(buffer, ",");
				strcat_s(buffer, string);
				strcpy_s(string, buffer);
			}
			else
			{
				strcpy_s(string, str);
			}
		}
		buffer[0] = '\0';
	}

	return 0;
}