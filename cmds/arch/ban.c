// ban.c	

void create()
{
	seteuid(getuid());
}

int main(object me, string arg)
{
	string *str, site;
	int num = 0;

	if (!arg) {
		BAN_D->print();
		return 1;
	}

	str = explode(arg, " ");
	switch (sizeof(str)) {
		case 2 : site = str[1]; break;
		case 3 : site = str[1]; num = atoi(str[2]); break;
		default : write("指令格式：ban [+|- 地址 [num]]\n"); return 1;
	}

	if (str[0] == "+")
		BAN_D->add(site, num);
	else if (str[0] == "-")
		BAN_D->delete(site, num);
	else	write("指令格式：ban [+|- 地址 [num]]\n");

	return 1;
}

int help(object me)
{
	write(@HELP
指令格式：ban [+|- 地址 [num]]

這條命令是用來封禁或解禁地址site。
若num為0或不接num，表示封禁一個確定的地址，不允許進行任何登錄；
若num為-1，表示封禁與該地址相匹配的多個地址，不允許進行任何登錄；
若num為正數，表示限制該地址最大登錄人數為num；
若地址為clear，則清除相應的列表。
HELP
);
	return 1;
}

