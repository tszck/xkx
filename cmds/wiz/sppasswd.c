// passwd.c

inherit F_CLEAN_UP;

void create()
{
	seteuid(getuid());
}
int main(object me, string arg)
{
	object ob,link_ob;
	string id,password;
	if(!arg||sscanf(arg,"%s %s",id,password)!=2)
		return notify_fail("瞧你要更改誰的密碼？更改密碼之前請三思一定要得到其本人同意。\n");
	ob=find_player(id);

	if(!ob)
	{
		ob = new(LOGIN_OB);
		ob->set("id",id);
		if( !ob->restore() ) return notify_fail("沒有這個玩家。\n");
		else
		{
			ob->set("password",crypt(password,0));
			ob->save();
			destruct(ob);
			return 1;
		}
	}
	link_ob=ob->query_temp("link_ob");
	if(link_ob)
	{
		link_ob->set("password",crypt(password,0));
		link_ob->save();
		return 1;
	}
	else
		return notify_fail("錯誤。無法進行修改。\n");
	return 1;
}


int help(object me)
{
	write(@HELP
指令格式 : passwd

這個指令可以修改你的人物密碼。

HELP
    );
    return 1;
}
