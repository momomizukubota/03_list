#define _CRT_SECURE_NO_WARNINGS

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

int main(int argc, char *argv[])
{
	char str[5];

	char string[512];
	char buffer[512];

	string[0] = '\0';
	while (fgets(str, sizeof(str), stdin)) {

		//-----------------------------------------------------
		//	�\��
		//-----------------------------------------------------
		if (atoi(str) == 0)
		{
			printf("%s\n", string);
		}

		//-----------------------------------------------------
		//	�폜
		//-----------------------------------------------------
		else if (atoi(str) == -1)
		{

			//�J���}���ǂ��ɂ��邩�T��
			char *rp = retComma(string);
			buffer[0] = '\0';
			//�J���}���܂܂�Ă��Ȃ��ꍇ�͐擪��\0
			if (string == rp)
			{
				strcpy(buffer, string);
				string[0] = '\0';
			}
			//�J���}���܂܂�Ă���ꍇ�̓J���}�ȍ~��string�փR�s�[����
			else
			{
				unsigned int len = (unsigned)(rp - string);
				int i = 0;
				for (; i < len; i++)
				{
					buffer[i] = string[i];
				}
				buffer[i] = '\0';

				strcpy(string, ++rp);
			}

			printf("%s\n", buffer);
		}

		//-----------------------------------------------------
		//	�ǉ�
		//-----------------------------------------------------
		else
		{
			trim(str);
			//�����񂪋󂶂�Ȃ��Ƃ��� str, ��ǉ�����
			if (string[0] != '\0')
			{
				strcpy(buffer, str);
				strcat(buffer, ",");
				strcat(buffer, string);
				strcpy(string, buffer);
			}
			else
			{
				strcpy(string, str);
			}
		}
		buffer[0] = '\0';
	}

	return 0;
}