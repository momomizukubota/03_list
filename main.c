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
	static const int TOTAL_LINE = 100;

	char str[5];

	char string[512];
	char buffer[512];

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

			//�J���}���ǂ��ɂ��邩�T��
			char *rp = retComma(string);
			buffer[0] = '\0';
			//�J���}���܂܂�Ă��Ȃ��ꍇ�͐擪��\0
			if (string == rp)
			{
				strcpy(buffer, string);
				string[0] = '\0';
			}
			//�J���}���܂܂�Ă���ꍇ�̓J���}�ȑO��string�փR�s�[����
			else
			{
				strncpy(buffer, string, (unsigned)(rp - string));
				strcpy(string, buffer);
			}

			printf("%s\n", buffer);
		}

		//�擪�ɒǉ�
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