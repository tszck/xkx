// /cmds/skill/research.c

// Modified by Constant Jan 11 2001

inherit F_CLEAN_UP;

#include <skill.h>
#include <ansi.h>


void create() { seteuid(getuid()); }

int main(object me, string arg)
{
	string skill, skill_name;
	object where = environment(me);
	int my_skill, jing_cost, times, pertimes;
//	int improve_points;
	int i;

	if (me->is_busy())
		return notify_fail("你現在正忙着呢。\n");

	if (!where->query("sleep_room"))
		return notify_fail("這裏太紛雜，你沒法做研究。\n");

	if(!arg || (sscanf(arg, "%s %d", skill, times)!=2 ))
		return notify_fail("指令格式：research|yanjiu <技能> <次數>\n");

	if (times < 1 || times > 100)
		return notify_fail("研究次數最少一次，最多也不能超過一百次。\n");

	if( me->is_fighting() )
		return notify_fail("臨陣磨槍？來不及啦。\n");

	if( !my_skill = me->query_skill(skill, 1) )
		return notify_fail("這項技能你恐怕沒法研究了。\n");

	if( (string)SKILL_D(skill)->type()=="knowledge")
		return notify_fail(to_chinese(skill)+"只能靠你學習才能提高的。\n");

	notify_fail("依你目前的能力，沒有辦法研究這種技能。\n");
	if(!SCBORN_D->valid_learn(me,skill) && !SKILL_D(skill)->valid_learn(me) && my_skill < 200) return 0;

	jing_cost = 300 / (int)me->query("int");
	if( !my_skill ) {
		jing_cost *= 2;
		me->set_skill(skill,0);
	}

	if( (me->query("potential") - me->query("learned_points")) < times )
		return notify_fail("你的潛能不夠研究這麼多次了。\n");
	printf(HIM"你研究了"+chinese_number(times)+"次有關「%s」的疑問。\n"NOR, to_chinese(skill));

	my_skill = me->query_skill(skill, 1);

	if( (string)SKILL_D(skill)->type()=="martial"
	&& my_skill * my_skill * my_skill / 10 > (int)me->query("combat_exp") )
	{
		return notify_fail("也許是缺乏實戰經驗，你沒法研究"+to_chinese(skill)+"的問題了。\n");
	} else
	{
    if (!me->query("env/auto_regenerate") && 
        				me->query("jing")< jing_cost * times)
		return notify_fail("你今天太累了，結果什麼也沒有研究成。\n");			
		for (pertimes = 0; pertimes < times ; pertimes ++)
		{
			if ((int)me->query("jing") < jing_cost)
      {
         if (me->query("env/auto_regenerate") &&
              SKILL_D("force/regenerate")->exert(me, me))
         {
              // try to regenerate & learn again
           write("你覺得精神好了一些，繼續進行研究。\n");
           pertimes--;
           continue;
         } else
         {
	          me->set("jing", 0);
            break;
         }
      }
      me->add("learned_points", 1);
     	me->receive_damage("jing", jing_cost );
		}
	}
	if (pertimes <= 0)
		return notify_fail("你今天太累了，結果什麼也沒有研究成。\n");

	for(i=0;i<pertimes;i++)
//		me->improve_skill(skill, random((int)me->query_int()/2));
		me->improve_skill(skill, (int)me->query_int()/8+random((int)me->query_int()/4));
	if(skill_name = SKILL_D(skill)->query_skill_name(my_skill))
	printf("你研究了一會，對「%s」這一招似乎想通了些什麼。\n", skill_name);
	else
	printf("你研究了一會，似乎對"+to_chinese(skill)+"有些新的領悟。\n");
	if (pertimes < times)
	return notify_fail("但是你今天太累了，研究了"+chinese_number(pertimes) +"次以後只好先停下來。\n");

	return 1;
}

int help(object me)
{
	write(@HELP
指令格式 : research | yanjiu <技能> <次數>

    這個指令可以讓你研究一種技能的疑難問題，當你師傅這項技能的級
別不如你的時候，可以通過研究自己來提高，當然進步的速度是不如向師
傅學的了。

    此外研究也需要消耗一些精氣和潛能，而消耗的精氣跟你自己的悟性
有關。

其他相關指令 : apprentice, practice, skills, study, learn
HELP
	);
	return 1;
}
