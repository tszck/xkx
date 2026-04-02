// kill.c
inherit F_CLEAN_UP;

#include <ansi.h>



int main(object me, string arg)
{
	object obj, hitter;
	string /**killer,*/ callname;
	seteuid(getuid());
	if( environment(me)->query("no_ansuan") )
		return notify_fail("這裏禁止戰鬥。\n");
	if( environment(me)->query("no_fight") )
		return notify_fail("這裏不準戰鬥。\n");
	if(me->is_busy())
		return notify_fail("你上一個動作還沒有完成！\n");
	if( !arg )
		return notify_fail("你想殺誰？\n");
	if(!objectp(obj = present(arg, environment(me))))
		return notify_fail("這裏沒有這個人。\n");
	if( !obj->is_character() || obj->is_corpse() )
		return notify_fail("看清楚一點，那並不是活物。\n");
//	if (userp(me)&& obj->query("owner") && me->query("id") != obj->query("owner"))
//    return notify_fail("不是你要抓的人，湊什麼熱鬧！\n");
//增加一個yinshi任務的限制條件		
	if( obj->query("no_kill") ||( obj->query("yinshi") && obj->query("ask_time")<=2) )
		return notify_fail("你真黑，居然下得了這個毒手！\n");
	
       if( objectp(hitter = obj->query_temp("last_damage_from")))
	{       
         	if( hitter->query("id") != me->query("id"))
		{
			if ((obj->query("name") ==
				me->query("family_quest/betrayer/name") ||
			obj->query("name") ==
				me->query("family_quest/thief/name") ||
			obj->query("name") ==
				me->query("quest/shan/quest") ||
			obj->query("name") ==
				me->query("quest/helian/quest")) &&
			(!living(obj) ||obj->query_temp("noliving") ||
				obj->query("qi") < obj->query("max_qi")/2) )
				return notify_fail("不是你打傷的，你不能殺了來完成任務。\n");
			else
				message_vision("\n$N對着$n得意地笑道：「"+obj->query("name")+"！今日活該你倒黴，欺侮你身上有傷，這個便宜我就不客氣了！」\n\n", me, obj);
		}
	}

	if(me->query("id") != obj->query_temp("bt_ownname") &&
		me->query_temp("bt/working"))
		return notify_fail("你身為捕快，執行公務，可不能殺良冒功！\n");
	if(obj==me) return notify_fail("用 suicide 指令會比較快:P。\n");
	if((int)obj->query("age") <= 15 && userp(obj))
		return notify_fail("為了世界更美好，放過小孩子吧.\n");

//限制大米pk  
  if( userp(obj) && obj->query_temp("noliving") && 
      obj->query("id") != me->query("last_die_by_id") &&
     (!objectp(hitter) || hitter->query("id")!= me->query("id")) &&
     me->query("combat_exp",1)<1000000)
          return notify_fail("想佔這樣的便宜，多練練再來吧!\n");
	if (userp(me) && userp(obj) && me->query("combat_exp")<100000 &&
	       obj->query("id") != me->query("last_die_by_id") &&
      obj->query("combat_exp")>1000000)
			return notify_fail("就憑你這點實力，還是少惹點事吧。")  ;       

	notify_fail("此人來頭不小，還是少惹為妙。\n");
	if (!userp(obj) && !obj->accept_kill(me)) return 0;		

	callname = RANK_D->query_rude(obj);
	if (random(3) > 1)
		message_vision("\n$N對着$n喝道：「" + callname + "！今日不是你死就是我活！」\n\n", me, obj);
	else
		message_vision("\n$N對着$n喝道：「" + callname + "！明年今日就是你的忌日！」\n\n", me, obj);

	me->delete("env/combatd");
	obj->delete("env/combatd");

	me->kill_ob(obj);
	if ( userp(obj))
		write_file("/log/static/ATTEMP_KILL", sprintf("%s   試圖殺死   %s on %s\n", me->name(1),obj->name(1), ctime(time()) ));
// Look for PKS 
	if( !userp(obj) ) 
	{
		if (!obj->query("owner") &&
		stringp(me->query("family/family_name")) &&
		(string)obj->query("family/family_name") == (string)me->query("family/family_name"))
		{
			if (living(obj) && !obj->query_temp("noliving"))
			message_vision(HIC"$n厲聲對$N道：你我本同門，卻為何想相害於我！\n"NOR,me,obj);
			me->delete("family/fealty");
			"/cmds/skill/expell"->main(obj,me->query("id"));
		}
		obj->kill_ob(me);
	}
	else
	{
		obj->fight_ob(me);
		tell_object(obj, HIR "如果你要和" + me->name() + "性命相搏，請你也對這個人下一次 kill 指令。\n" NOR);
	}

	return 1;
}
int help(object me)
{
	write(@HELP
指令格式 : kill <人物>
 
    這個指令讓你主動開始攻擊一個人物，並且試圖殺死對方，kill 和 fight 
最大的不同在於雙方將會真刀實槍地打鬥，也就是説，會真的受傷。由於 kill 
只需單方面一廂情願就可以成立，因此你對任何人使用 kill 指令都會開始戰鬥，
通常如果對方是 NPC 的話，他們也會同樣對你使用 kill。

    當有人對你使用 kill 指令時會出現紅色的字樣警告你，對於一個玩家而言，
如果你沒有對一名敵人使用過 kill 指令，就不會將對方真的打傷或殺死（使用
毒術除外）。

其他相關指令: hit, fight

HELP
	);
	return 1;
}
 
