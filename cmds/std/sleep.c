// /cmds/std/sleep.c
// Dec.11 1997 by Venus
// Modified by Zeratul Jan 11 2001 記錄夫妻上次交流時間
//第60行注意了：ahda
//Modified by Qingyun 2004.9.30 調整睡覺時間長度、把baby改成condition懷孕

#include <ansi.h>
#include <command.h>
void wakeup(object me, object where);
int wakeup2(object me,object slept,object where);
void del_sleeped(object me);

int main(object me, string arg)
{
	object obj, old_target;
	int i,sleeptime;
	object *inv;
	mapping fam;
	object where = environment(me);

	seteuid(getuid());

	if ( (!(fam = me->query("family")) ||
		fam["family_name"] != "丐幫") &&
		!(where->query("sleep_room")) ||
		(where->query("no_sleep_room")) ||
                (where->query_temp("no_sleep")))
		return notify_fail("這裏不是你能睡的地方！\n");
	if( me->query_temp("no_sleep") ) return notify_fail("你現在睡不着覺。\n");
	if( me->query_temp("noliving") ) return notify_fail("");   // 非活動玩家
	if( me->is_busy()) return notify_fail("你正忙着呢！\n");
	if( me->is_fighting() ) return notify_fail("戰鬥中不能睡覺！\n");
	if( (fam = me->query("family")) && fam["family_name"] == "丐幫")
	{
		inv = all_inventory(where);
		for(i=0; i<sizeof(inv); i++)
	if((living(inv[i]) || !inv[i]->query_temp("noliving")) &&
	inv[i]!=me && inv[i]->is_fighting())
			return notify_fail("這裏有人在打架，你還照樣睡？\n");
	}
	if (where->query("hotel") && !(me->query_temp("rent_paid")))
	{
		message_vision("店小二從門外對$N大叫：把這裏當避難所啊！先到一樓付錢後再來睡！\n",me);
		return 1;
	}
	//限制連續睡覺
	if (me->query_temp("sleeped"))
		return notify_fail("你剛睡過一覺，先活動活動吧。 \n");
//加上感冒不能睡覺
		if (me->query_condition("ill_kesou"))
				{
					tell_object(me, "你想合上眼睛好好睡上一覺，可是" +
					"咳嗽"+"不斷折磨着你，讓你輾轉難眠。\n");
					return 1;
				}
		if (me->query_condition("ill_shanghan"))
				{
					tell_object(me, "你想合上眼睛好好睡上一覺，可是" +
					"傷寒"+"不斷折磨着你，讓你輾轉難眠。\n");
					return 1;
				}
		if (me->query_condition("ill_fashao"))
				{
					tell_object(me, "你想合上眼睛好好睡上一覺，可是" +
					"發燒"+"不斷折磨着你，讓你輾轉難眠。\n");
					return 1;
				}
		if (me->query_condition("ill_dongshang"))
				{
					tell_object(me, "你想合上眼睛好好睡上一覺，可是" +
					"凍傷"+"不斷折磨着你，讓你輾轉難眠。\n");
					return 1;
				}
		if (me->query_condition("ill_zhongshu"))
				{
					tell_object(me, "你想合上眼睛好好睡上一覺，可是" +
					"滿身的熱氣" + "不斷折磨着你，讓你輾轉難眠。\n");
					return 1;
				}
// 感冒到此結束 
	if((!arg) || arg==(string)me->query("id"))
	{
		if (where->query("sleep_room"))
		{
			write("你往牀上一躺，開始睡覺。\n");
			write("不一會兒，你就進入了夢鄉。\n");
			me->set_temp("block_msg/all",1);
			message_vision("$N一歪身，倒在牀上，不一會便鼾聲大作，進入了夢鄉。\n",me);
		}
		else
		{
			write("你往地下角落一躺，開始睡覺。\n");
			write("不一會兒，你就進入了夢鄉。\n");
			me->set_temp("block_msg/all",1);
			message_vision("$N往地下角落屈身一躺，不一會便鼾聲大作，做起夢來。\n",me);
		}
		where->add("no_fight", 1);
		where->add_temp("sleeping_person", 1);

		me->set("no_get", 1);
		me->set("no_get_from", 1);
		me->set_temp("sleeped",1);


		if( userp(me) ) me->set_temp("noliving/sleeped", 1);
		else me->disable_player("<睡夢中>");
//	call_out("wakeup", random(45-me->query("con"))+45, me, where);
		sleeptime=random(45-me->query("con"))+20;
		if (me->query("mud_age")<86400*4)//18以下加快醒來
			sleeptime-=20;
		if (where->query("hotel")) 
		{//客棧睡覺時間減少
			me->delete_temp("rent_paid");
			sleeptime=sleeptime*1/2;
		}
		if (sleeptime < 10) sleeptime=10;
//		call_out("wakeup", sleeptime, me, where);
		me->start_call_out((:call_other,__FILE__,"wakeup",me,where:),sleeptime);
		return 1;
	}
	if(!objectp(obj = present(arg, where)))
		return notify_fail("你想跟誰一起睡？\n");
	if( !obj->is_character() )
		return notify_fail("？腦袋出毛病了？\n");
// can't sleep with npc...
	if( !userp(obj) )
		return notify_fail("人家可不願理你！\n");
	if(me->query("gender") == "無性")
		return notify_fail("你是太監啊．．．\n");
	if(me->query("gender") == obj->query("gender"))
		return notify_fail("？對方跟你可是同性呢．．．\n");
	if( !living(obj) || obj->query_temp("noliving") )
		return notify_fail(obj->name() + "沒法跟你睡了。\n");
	if (!where->query("if_bed"))
		return notify_fail("就在這裏？不太好吧。\n");
	if( (int)me->query("qi") * 100 / (int)me->query("max_qi") < 50 )
		return notify_fail("你現在是心有餘而力不足。\n");

	if( userp(obj) && (object)obj->query_temp("pending/sleep")!=me )
	{
		message_vision(RED"\n$N含情脈脈地對$n説：我．．．\n\n"NOR, me, obj);
		if( objectp(old_target = me->query_temp("pending/sleep")) &&
			!((string)old_target->query("id")==(string)obj->query("id")))
			tell_object(old_target, YEL + me->name() + "改變主意不想跟你睡了。\n" NOR);
		me->set_temp("pending/sleep", obj);
		tell_object(obj, YEL "看來" + me->name() + "("+(string)me->query("id")+")"+ "很想跟你．．．如果你願意，請也下一次 sleep 指令。\n" NOR);
		write(YEL "對方正在考慮中．．．\n" NOR);
		return 1;
	}
	message_vision(RED "\n$N衝着$n會心地一笑，點了點頭。\n\n" NOR, me, obj);

	inv = all_inventory(me);
	for(i=0; i<sizeof(inv); i++)
		REMOVE_CMD->do_remove(me, inv[i]);
	inv = all_inventory(obj);
	for(i=0; i<sizeof(inv); i++)
		REMOVE_CMD->do_remove(obj, inv[i]);

	if(me->query("gender")=="男性")
	{
		tell_object(me, HIY"\n\n你摟着"+obj->query("name")+"溫軟的身體，不由得心醉神迷．．．\n\n\n" NOR);
		tell_object(obj, HIY"\n\n你躺在"+me->query("name")+"的懷裏，不由得心醉神迷．．．\n\n\n" NOR);
	}
	else
	{
		tell_object(obj, HIY"\n\n你摟着"+me->query("name")+"溫軟的身體，不由得心醉神迷．．．\n\n\n" NOR);
		tell_object(me, HIY"\n\n你躺在"+obj->query("name")+"的懷裏，不由得心醉神迷．．．\n\n\n" NOR);
	}
	me->set("last_slp",me->query("mud_age"));
	obj->set("last_slp",obj->query("mud_age"));
	if (me->query("couple/couple_id")==obj->query("id"))		me->set("last_sleep_couple",time());
	if (obj->query("couple/couple_id")==me->query("id"))		obj->set("last_sleep_couple",time());
	me->set_temp("block_msg/all",1);
	obj->set_temp("block_msg/all",1);
	me->delete_temp("pending/sleep");
	obj->delete_temp("pending/sleep");
	message_vision(HIY "$N和$n鑽入被中，摟在一起睡着了．．．\n\n\n" NOR,me,obj);
	if( userp(me) ) me->set_temp("noliving/sleeped", 1);
	else me->disable_player("<睡夢中>");
	if( userp(obj) ) obj->set_temp("noliving/sleeped", 1);
	else obj->disable_player("<睡夢中>");
// 做記錄
	if (!me->query("sex/number"))
		me->set("sex/first",obj->query("id"));
	me->add("sex/number",1);
	me->add("sex/"+obj->query("id"),1);
	if (!obj->query("sex/number"))
		obj->set("sex/first",me->query("id"));
	obj->add("sex/number",1);
	obj->add("sex/"+me->query("id"),1);
// 記錄結束

//	call_out("wakeup2",random(45 - me->query("con")) + 30+3, me,obj, where);
//	call_out("wakeup2",random(45 - obj->query("con")) + 30+1, obj, me,where);
  me->start_call_out((:call_other,__FILE__,"wakeup2",me,obj,where:),random(45 - me->query("con")) + 30+1);
	obj->start_call_out((:call_other,__FILE__,"wakeup2",obj,me,where:),random(45 - obj->query("con")) + 30+3);
	return 1;
}
void wakeup(object me,object where)
{
	if(!me) return;
	me->delete("no_get");
	me->delete("no_get_from");
	if (!me->query_temp("block_msg/all"))	return;// 已經能看到東西了 就無所謂醒過來
	if ((me->query("mud_age")-me->query("last_slp"))<120 && me->query("max_jing")>160)
	{
		//在時間限制內  恢復一半的精氣和四分一內力
		//精氣短的比如新手也讓恢復一半 
		me->add("qi", me->query("eff_qi")/2 - me->query("qi")/2 );
		me->add("jing", me->query("eff_jing")/2 - me->query("jing")/2 );
		if (me->query("neili") < me->query("max_neili"))
			me->add("neili", me->query("max_neili")/4 - me->query("neili")/4 );
		me->add("tili", me->query("max_tili")/2 - me->query("tili")/2 );
		message_vision("$N迷迷糊糊的睜開眼睛，懶散無神的爬了起來。\n",me);
		me->set_temp("block_msg/all", 0);
		tell_object(me, "你一覺醒來，由於睡得太多，精神沒有恢復多少。\n");
	}
	else
	{
		me->set("qi", me->query("eff_qi"));
		me->set("jing", me->query("eff_jing"));
//		if (me->query("neili") < me->query("max_neili"))
		me->add("neili", me->query("max_neili")/2 - me->query("neili")/2 );
		me->set("tili", me->query("max_tili") );
		me->set("last_slp",me->query("mud_age"));//記錄最近一次完全睡眠的時間
		message_vision("$N一覺醒來，精力充沛地活動了一下筋骨。\n",me);
		me->set_temp("block_msg/all", 0);
		tell_object(me, "你一覺醒來，只覺精力充沛。該活動一下了。\n");
	}

	if( userp(me)) me->delete_temp("noliving");
	else me->enable_player();

//	remove_call_out("del_sleeped");

//	call_out("del_sleeped", 1, me);//兩次睡覺不管怎樣都限制 這裏限制1s
	me->start_call_out((:call_other,__FILE__,"del_sleeped",me:),1);

	if (where->query("no_fight") >= 2)
		where->add("no_fight", -1);
	else
		if ((!where->query("sleep_room") && !where->query("hotel")) ||
			where->query("no_fight")==1 )
			where->delete("no_fight");

	where->add_temp("sleeping_person", -1);
	return;
}

int wakeup2(object me,object slept,object where)
{
	int qi_cost;
	object obj;

	me->set("qi", me->query("eff_qi"));
	me->set("jing", me->query("eff_jing"));
	me->add("neili", me->query("max_neili")/2 - me->query("neili")/2 );
	if( userp(me)) me->delete_temp("noliving");
	else me->enable_player();

	qi_cost=50+5*((int)me->query("str")-(int)me->query("con"));
	if(qi_cost>(int)me->query("max_qi")/2)
		qi_cost=(int)me->query("max_qi")/2+1;
	me->add("qi", -qi_cost);
	if (me->query("qi") <= 0) me->set("qi", 10);

	while( environment(me)->is_character() )
	me->move(environment(environment(me)));

	if(me->query("gender")!="女性")
	{
		message_vision(HIY"$N醒了過來，似乎還沉浸在幸福之中。\n"NOR,me);
		me->set_temp("block_msg/all", 0);
		tell_object(me, "你醒了過來，似乎還沉浸在幸福之中。\n");
		return 1;
	}
	else
	{
		message_vision(HIY"$N醒了過來，臉上還掛着甜蜜的笑容。\n"NOR,me);
		me->set_temp("block_msg/all", 0);
		tell_object(me, "你醒了過來，臉上還掛着甜蜜的笑容。\n");
		obj=slept;

		if((int)(me->query("mud_age")/86400) < 4 ||
			(int)(me->query("mud_age")/864000) < me->query("child") ||
			(int)(me->query("mud_age")/86400) > 36  
			)
			return 1;

		if (me->query_condition("huaiyun"))	return 1;			

		if (!me->query("child") || random(me->query("sex/"+slept->query("id"))) > me->query("age")/2*me->query("child"))
			{
				if(me->query_temp("no_huaiyun")) // 以後增加和這個對應的obj
				{
					message_vision(HIY "\n$N忽覺腹中一陣顫動，不過馬上又平靜下來。\n"NOR,me);
					return 1;
				}
//				tell_object(me,"你忽然感覺有點頭暈，不過馬上又恢復了過來。\n");
				me->set("baby/father",slept->query("id"));
				me->set("baby/gender",random(2)+1);
				me->apply_condition("huaiyun",3200); //一個月約 320 heart beat 
			}
			return 3;
	}
}

void del_sleeped(object me)
{
	if (objectp(me) && me->query_temp("sleeped"))
		me->delete_temp("sleeped");
}
int help(object me)
{
	write(@HELP
指令格式 : sleep <人物>
 
    顧名思義，這個指令是用來睡覺的。恢復精和氣的有效途徑，但睡
覺時是閉着眼的，所以.......要小心哦。

    如果和配偶睡的話，就有機會生下小孩了。:)
HELP
	);
	return 1;
}
