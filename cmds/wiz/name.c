// nick.c
inherit F_CLEAN_UP;

#include <ansi.h>



int main(object me, string arg)
{
	string name, id ,to,what;
	object obj=me;
	if( !arg ) return notify_fail("你要替誰取什麼名字？\n");
	if (sscanf(arg, "%s %s(%s)", to,name, id) == 3)
	{
				what="name";
				if (!obj=present(to, environment(me)))
				if (!obj=find_player(to))
							return notify_fail("沒有這個人。\n");
	}
	else if (sscanf(arg,"%s cancel",to)==1)
	{
				what="cancel";
				if (!obj=present(to, environment(me)))
				if (!obj=find_player(to))
							return notify_fail("沒有這個人。\n");
	}
	else if (sscanf(arg,"%s(%s)", name,id)==2)
	{
			 what="name";
	}
	else if (arg=="cancel") 
	{
			what="cancel";
	}
	else
	{
			return notify_fail("語法格式：name [某人] [cancel] [中文名(id)]\n");
	}
	if (what=="cancel")
	{
		if (!obj->query("old_name") || !obj->query("old_id"))
			return notify_fail(obj->query("name")+"並沒有用name命令改名過。\n");
		else
		{
			write("你把 "+obj->query("name")+"("+obj->query("id")+") 的名字");
			obj->set("id",obj->query("old_id"));
			obj->set("name",obj->query("old_name"));
			obj->delete("old_id");
			obj->delete("old_name");
			write("恢復成了 "+obj->query("name")+"("+obj->query("id")+") 。\n");
			return 1;
		}
	}
	else if (what=="name")
	{
	name = replace_string(name, "$BLK$", BLK);
	name = replace_string(name, "$RED$", RED);
	name = replace_string(name, "$GRN$", GRN);
	name = replace_string(name, "$YEL$", YEL);
	name = replace_string(name, "$BLU$", BLU);
	name = replace_string(name, "$MAG$", MAG);
	name = replace_string(name, "$CYN$", CYN);
	name = replace_string(name, "$WHT$", WHT);
	name = replace_string(name, "$HIR$", HIR);
	name = replace_string(name, "$HIG$", HIG);
	name = replace_string(name, "$HIY$", HIY);
	name = replace_string(name, "$HIB$", HIB);
	name = replace_string(name, "$HIM$", HIM);
	name = replace_string(name, "$HIC$", HIC);
	name = replace_string(name, "$HIW$", HIW);
	name = replace_string(name, "$NOR$", NOR);
	id = replace_string(id, "$BLK$", BLK);
	id = replace_string(id, "$RED$", RED);
	id = replace_string(id, "$GRN$", GRN);
	id = replace_string(id, "$YEL$", YEL);
	id = replace_string(id, "$BLU$", BLU);
	id = replace_string(id, "$MAG$", MAG);
	id = replace_string(id, "$CYN$", CYN);
	id = replace_string(id, "$WHT$", WHT);
	id = replace_string(id, "$HIR$", HIR);
	id = replace_string(id, "$HIG$", HIG);
	id = replace_string(id, "$HIY$", HIY);
	id = replace_string(id, "$HIB$", HIB);
	id = replace_string(id, "$HIM$", HIM);
	id = replace_string(id, "$HIC$", HIC);
	id = replace_string(id, "$HIW$", HIW);
	id = replace_string(id, "$NOR$", NOR);

	write("你把 "+obj->query("name")+"("+obj->query("id")+") ");	
	obj->set("old_name",obj->query("name"));
	obj->set("old_id",obj->query("id"));
	obj->set("name", name);
	obj->set("id", id);
	write("改名爲 "+obj->query("name")+"("+obj->query("id")+") 。\n");
	}
	else 
	{
		write("你可以考慮向青雲要些bug獎勵。\n");
	}
	return 1;
}
int help(object me)
{
	write(@HELP
指令格式 : name 名字(id)
           name cancel
           name dami 大米(dummy)
           name dami cancel
					 
 
你如果希望在名字中使用ansi的控制字元改變顏色，可以用以下的控制
字串：

        $ＢＬＫ$：[30m黑色[0m          
        $ＲＥＤ$：[31m紅色[0m          $ＨＩＲ$：[1;31m亮紅色[0m
        $ＧＲＮ$：[32m綠色[0m          $ＨＩＧ$：[1;32m亮綠色[0m
        $ＹＥＬ$：[33m土黃色[0m        $ＨＩＹ$：[1;33m黃色[0m
        $ＢＬＵ$：[34m深藍色[0m        $ＨＩＢ$：[1;34m藍色[0m
        $ＭＡＧ$：[35m淺紫色[0m        $ＨＩＭ$：[1;35m粉紅色[0m
        $ＣＹＮ$：[36m藍綠色[0m        $ＨＩＣ$：[1;36m天青色[0m
        $ＷＨＴ$：[37m淺灰色[0m        $ＨＩＷ$：[1;37m白色[0m
        $ＮＯＲ$：[0m恢復正常顏色[0m

HELP
	);
	return 1;
}
