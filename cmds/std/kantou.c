// kantou.c
inherit F_CLEAN_UP;

#include <ansi.h>


int do_kan(object me, object ob, object weapon);

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
	object obj/*, *inv*/, weapon;

	if( !arg ) return notify_fail("你要砍誰的頭？\n");

	if( me->is_busy() )
		return notify_fail("你上一個動作還沒有完成！\n");

	if (!objectp(weapon = me->query_temp("weapon")) ||
		((string)weapon->query("skill_type") != "sword" &&
		(string)weapon->query("skill_type") != "axe" &&
		(string)weapon->query("skill_type") != "dagger" &&
		(string)weapon->query("skill_type") != "hook" &&
		 (string)weapon->query("skill_type") != "blade"))
		return notify_fail("你不用利器哪裏砍得動！\n");
	if(!objectp(obj = present(arg, environment(me))))
		return notify_fail("你只能砍屍體的頭。\n");
	if(userp(obj) || living(obj) )
		return notify_fail("那還是活的！先殺了才能砍頭！\n");
	if( me->is_fighting() )
		return notify_fail("你還在戰鬥中！還想砍人家的頭？\n");
	return do_kan(me, obj, weapon);
}
	
int do_kan(object me, object obj, object weapon)
{
	object newob;
	string newname;

	if( !obj ) return 0;
	if( obj->query("kantou") == 1)
	{
		message_vision( "$N是個無頭屍。\n", obj );
		return 1;
	}
	newname = obj->query("name");
	if( strsrch(newname, "腐爛的屍體") >= 0)
	{
		message_vision( "腐屍還砍個啥勁呀。\n", obj );
		return 1;
	}
	if(strsrch(newname, "屍體") >= 0)
		newname = replace_string(newname, "屍體", "頭顱");
	else
	{
		message_vision(obj->query("name")+"有什麼頭可砍的。\n", obj );
		return 1;
	}
	newob = new("/clone/misc/head");
	newob ->set("name", HIR+newname+NOR);
	newob ->move(me);
	if( obj->query("userp") == 1) newob-> set("userp", 1);
	if( obj->query("quest") ) newob-> set("quest", obj->query("quest"));
	if( obj->query("owner")) newob->set("owner",obj->query("owner"));
	if( me->is_fighting() ) me->start_busy(1);
	message_vision( "$N揮起"+weapon->query("name")+"將$n的腦袋砍了下來。\n", me, obj );
	obj->set("kantou", 1);
	newname = obj->query("name");
	if(strsrch(newname, "屍體") >= 0)
		newname = replace_string(newname, "屍體", "無頭屍體");
	obj->set("name", newname);
	return 1;
}

int help(object me)
{
	write(@HELP
指令格式 : kantou <屍體名稱>
 
    這個指令可以讓你砍下地上死者的頭顱。
    很多任務要求砍頭獻功的。
 
HELP
	);
	return 1;
}
 