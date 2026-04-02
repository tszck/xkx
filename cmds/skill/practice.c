// /cmds/skill/practice.c
// Modified by Zeratul 減慢練習速度
inherit F_CLEAN_UP;

#include <ansi.h>



int main(object me, string arg)
{
	object where = environment(me);
	string skillname;
	int skill, skill_basic, times, pertimes;
	int improve_points = 0;

	seteuid(getuid());

	if (where->query("pigging"))
		return notify_fail("你還是專心拱豬吧！\n");
	if (where->is_chat_room())
	  return notify_fail("這裏禁止練功。\n");
	if (me->is_busy())
		return notify_fail("你現在正忙着呢。\n");
	if( me->is_fighting() )
		return notify_fail("你已經在戰鬥中了，學一點實戰經驗吧。\n");
	if( !arg ) return (__DIR__"enable")->main(me, arg);
	if ( (sscanf(arg, "%s %d", arg, times)!=2 ))
		return notify_fail("指令格式：practice|lian <技能種類> <次數>\n");
	if ( times < 1 || times > 30)
		return notify_fail("練習次數必須大於一次，但不能超過三十次。\n");
	if( !stringp(skillname = me->query_skill_mapped(arg)) )
		return notify_fail("你只能練習用 enable 指定的特殊技能。\n");
	skill_basic = me->query_skill(arg, 1);
	skill = me->query_skill(skillname, 1);
	if( skill < 1 )
		return notify_fail("你好像還沒有學過這項技能吧？最好先去請教別人。\n");
	if( skill_basic < 1 )
		return notify_fail("你對這方面的技能還是一竅不通，最好從先從基本學起。\n");
	if( skill_basic/2 <= skill/3 )
		return notify_fail("你的基本功火候未到，必須先打好基礎才能繼續提高。\n");

	notify_fail("你現在不能練習這項技能。\n");
	if(!SCBORN_D->valid_learn(me,skillname) && !SKILL_D(skillname)->valid_learn(me) ) return 0;

	notify_fail("你試着練習" + to_chinese(skillname) + "，但是並沒有任何進步。\n");
	if (skill*skill*skill/10 > (int)me->query("combat_exp")) 
	{
		return notify_fail("也許是缺乏實戰經驗，你的練習總沒法進步。\n");
	}

	write( HIC "你試着把" + to_chinese(skillname) + "練了"+chinese_number(times)+"趟。\n" NOR);
	for (pertimes = 1; pertimes <= times; pertimes ++)
	{
		if( SKILL_D(skillname)->practice_skill(me) )
		{
// 練習速度 = 基本武功的平方除本武功再除5，加武功練習補償。
// 未定義練習補償的技能，默認爲10。
			improve_points = (skill_basic*skill_basic)/( skill+1);
			improve_points = random( improve_points / 5 ) + 1;
			if(SKILL_D(skillname)->practice_bonus())
				improve_points += SKILL_D(skillname)->practice_bonus();
			else improve_points += 10;
			me->improve_skill(skillname, improve_points, skill_basic > skill? 0: 1);
		}
		else return 0;
	}
	write( HIY "你的" + to_chinese(skillname) + "進步了！\n" NOR);
//	me->start_busy(1);
	return 1;
}

int help(object me)
{
	write(@TEXT
指令格式：practice | lian <技能種類> <次數>

    這個指令讓你練習某個種類的技能，這個技能必須是經過 enable 的
專業技能。

    如果你對這方面的基本技能夠高，可以經由練習直接升級，而且升級
的上限只跟你基本技能的等級有關，換句話說，勤加練習是使你的所學「
青出於藍勝於藍」的唯一途徑，當然，在這之前你必須從實際運用中獲得
足夠的經驗以提升你的基本技能。

    如果你現在學會的這招已經練到完全純熟了，這時再練系統會提示你
現有的招式已經練熟了，以你的武學修爲是無法自己練出下一招來的，所
以你需要去找師傅學習新的招式，一旦學會新的招式，就可以繼續練習新
的那招了。注意練習是要消耗體力的。

TEXT
	);
	return 1;
}
