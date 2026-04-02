// ce.c
inherit F_CLEAN_UP;

#include <ansi.h>
#include <net/dns.h>



int help(object me);
void create() {seteuid(getuid());}

int main(object me, string arg)
{
	object obj;
	int flag=1;
	if(!me->query("couple/have_couple")) return help(me);

	obj = find_player(me->query("couple/couple_id"));

		if(!obj || (!wizardp(me) && !me->visible(obj)))
			flag=0;

//	if (!wizardp(me) && obj->query_temp("pigging_seat"))
//		return notify_fail("你的伴侶正在拱豬，聽不到悄悄話....\n");

	if( !arg )
	{
//		message_vision(MAG "\n$N多麼思念"+me->query("couple/couple_gender")+me->query("couple/couple_name")+"啊，可是伊人何方呢...\n"NOR, me);
		write(MAG "\n你多麼思念"+me->query("couple/couple_gender")+me->query("couple/couple_name")+"啊，可是伊人何方呢...\n"NOR);
		if (flag)
		tell_object(obj,MAG"\n你的"+obj->query("couple/couple_gender")+"在思念你... ...\n" NOR);
	}
	else
		switch (arg)
		{
			case "kiss":
				if( objectp(present(me->query("couple/couple_id"), environment(me))) )
//					message_vision(MAG "\n$N擁抱着$n深深地一吻...\n"NOR, me, obj);
				{
					write(MAG "\n你擁抱着"+me->query("couple/couple_name")+"深深地一吻...\n"NOR);
					tell_object(obj,MAG"\n"+obj->query("couple/couple_name")+"擁抱着你深深地一吻...\n" NOR);
				}
				else
				{
					write(MAG "\n你多想擁抱你的" + me->query("couple/couple_gender") + "深深地一吻...\n" NOR);
					if (flag)
					tell_object(obj, MAG "\n你的"+obj->query("couple/couple_gender")+"多想擁抱你，給你深深的一吻... ...\n" NOR);
				}
				break;	
			case "bye":
				if( objectp(present(me->query("couple/couple_id"), environment(me))) )
//					message_vision(MAG "\n$N含淚凝望着$n，哽咽道: 又要再見了，何時才能長相聚不分離呀...\n"NOR, me, obj);
				{
							write(MAG "\n你含淚凝望着"+me->query("couple/couple_name")+"，哽咽道: 又要再見了，何時才能長相聚不分離呀...\n"NOR);
							tell_object(obj,MAG "\n"+obj->query("couple/couple_name")+"含淚凝望着你，哽咽道: 又要再見了，何時才能長相聚不分離呀...\n"NOR);
				}
				else
				{
					if (me->query("gender")=="女性")
					{
						write(MAG"\n你多想再多看你的"+me->query("couple/couple_gender")+"一眼，讓他知道你是這樣的一直念掛着他...\n"NOR);
					if (flag)
						tell_object(obj, sprintf(MAG "\n你的%s多想再多看你一眼，山遙水隔，她會一直記掛你的，你要自己保重啊... ...\n" NOR, obj->query("couple/couple_gender")));
					}
					else
					{
						write(MAG"\n你多想再多看你的"+me->query("couple/couple_gender")+"一眼，讓她知道你是這樣的一直念掛着她...\n"NOR);
					if (flag)
						tell_object(obj, MAG "\n你的"+obj->query("couple/couple_gender")+"多想再多看你一眼，山遙水隔，他會一直記掛你的，你要自己保重啊... ...\n" NOR);
					}
				}
				break;
			default:
			if (!flag)
				if (me->query("gender")=="女性")
					return notify_fail(MAG"你想和你的" + me->query("couple/couple_gender")+"説説話，可是他現在不在線上。\n"NOR);
				else
					return notify_fail(MAG"你想和你的" + me->query("couple/couple_gender")+"説説話，可是她現在不在線上。\n"NOR);
			write(MAG "你悄悄告訴你的" + me->query("couple/couple_gender") + "：" + arg + "\n" NOR);
			tell_object(obj, sprintf( MAG "你的%s悄悄告訴你：%s\n" NOR, obj->query("couple/couple_gender"), arg));
//				message("channel:snp", HIB"【監聽】" + me->name() + "悄悄告訴"+ obj->name() + "：" + arg + "\n"NOR, users());
// 				聽別人私房話不好吧?
		}
		return 1;
}

int help(object me)
{
	write(@HELP

指令格式：ce [kiss | bye] [<訊息>]

    你可以用這個指令對你的伴侶説悄悄話。

HELP
	);
	return 1;
}
