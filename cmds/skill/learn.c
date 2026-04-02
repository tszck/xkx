// /cmds/skill/learn.c

// Modified by Constant Jan 11 2001

inherit F_CLEAN_UP;

#include <skill.h>
#include <ansi.h>


string *reject_msg = ({
	"說道：您太客氣了，這怎麼敢當？\n",
	"像是受寵若驚一樣，說道：請教？這怎麼敢當？\n",
	"笑着說道：您見笑了，我這點雕蟲小技怎夠資格「指點」您什麼？\n",
});

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
	string skill, teacher/*, master*/, skill_name;
	object ob;
	int master_skill, my_skill, jing_cost, times, pertimes;
	int improve_points;
	 mixed flag;
	 int i;
	 
	if (me->is_busy())
		return notify_fail("你現在正忙着呢。\n");
	if (environment(me)->is_chat_room())
	  return notify_fail("這裏禁止練功。\n");
	if(!arg || (sscanf(arg, "%s %s %d", teacher, skill, times)!=3 ))
		return notify_fail("指令格式：learn|xue <某人> <技能> <次數>\n");
	if (times < 1 || times > 100)
		return notify_fail("學習次數最少一次，最多也不能超過一百次。\n");
	if( me->is_fighting() )
		return notify_fail("臨陣磨槍？來不及啦。\n");
	if( !(ob = present(teacher, environment(me))) || !ob->is_character())
		return notify_fail("你要向誰求教？\n");
	if( !living(ob) || ob->query_temp("noliving") )
		return notify_fail("嗯....你得先把"+ob->name()+"弄醒再說。\n");

  notify_fail( ob ->name() + reject_msg[random(sizeof(reject_msg))] );
	if( !me->is_apprentice_of(ob) && !(ob->recognize_apprentice(me,skill)) )
	{
		return	0;	
	}
	if( !master_skill = ob->query_skill(skill, 1) )
		return notify_fail("這項技能你恐怕必須找別人學了。\n");

	if (stringp(flag = ob->query("no_teach/" + skill)))
	{
		message_vision(CYN "$N" CYN "搖搖頭，說道：" + flag + "\n" NOR, ob);
		return 1;
	} else
	if (intp(flag) && flag)
	{
		if (flag != 1)
			// show the messaeg if the result was not -1
			write(CYN + ob->name() + CYN "說道：對不起，" +
				to_chinese(skill) + "可不能隨便傳授。\n" NOR);
					return 1;
	}

  notify_fail(ob->name() + "不願意教你這項技能。\n");
	if( ob->prevent_learn(me, skill) )
		return 0;
	my_skill = me->query_skill(skill, 1);
	if( my_skill >= master_skill )
		return notify_fail("這項技能你的程度已經不輸你師父了。\n");
	if( my_skill >= (int)(master_skill - me->query("betrayer")*2))
		return notify_fail(ob->name() +"皺了皺眉頭，不禁想起你過去的叛師經歷。\n");
	if ( userp(ob) && my_skill >= 200 )
		return notify_fail("依你目前的能力，已不需向玩家學習了。\n");
	if ((SKILL_D(skill)->type())!="knowledge" && my_skill >= 250)
	  return notify_fail(ob->name() + "說道：你" + to_chinese(skill) +"的功力已經是非同凡響了，我就不再教你，你自己多研究吧。\n");
	notify_fail("依你目前的能力，沒有辦法學習這種技能。\n");
	if( !SKILL_D(skill)->valid_learn(me) ) 
	return 0;

	jing_cost = 150 / (int)me->query("int");
	if( !my_skill )
	{
		jing_cost *= 2;
		me->set_skill(skill,0);
	}

	if( (me->query("potential") - me->query("learned_points")) < times )
		return notify_fail("你的潛能不夠學習這麼多次了。\n");
	printf(HIC"你向%s請教了"+chinese_number(times)+"句有關「%s」的疑問。\n"NOR, ob->name(), to_chinese(skill));
	if( ob->query("env/no_teach") )
		return notify_fail("但是" + ob->name() + "現在並不準備回答你的問題。\n");
	tell_object(ob, sprintf("%s向你請教有關「%s」的問題。\n",
		me->name(), to_chinese(skill)));
	if (userp(ob))
	if(  (int)ob->query("jing") > jing_cost*times/5 + 1 )
	{
		  ob->receive_damage("jing", jing_cost/5 + 1);
	}
	else
	{
		write("但是" + ob->name() + "顯然太累了，沒有辦法教你什麼。\n");
		tell_object(ob, "但是你太累了，沒有辦法教"+me->name()+"。\n");
		return 1;
	}
		if( (string)SKILL_D(skill)->type()=="martial" &&
		my_skill*my_skill*my_skill/10 > (int)me->query("combat_exp") )
		{
			return notify_fail("也許是缺乏實戰經驗，你對"+ob->name()+"的回答總是無法領會。\n");
		}
    if (!me->query("env/auto_regenerate") && 
        				me->query("jing")< jing_cost * times)
							return notify_fail("你今天太累了，結果什麼也沒有學到。\n");
//	if( (int)me->query("jing") > jing_cost * times )
			for (pertimes = 0; pertimes < times ; pertimes ++)
			{
				if ((int)me->query("jing") < jing_cost)
        {
            if (me->query("env/auto_regenerate") &&
                SKILL_D("force/regenerate")->exert(me, me))
              {
              // try to regenerate & learn again
               write("你覺得精神好了一些，繼續進行學習。\n");
               pertimes--;
                continue;
            } else
              {
//             me->set("jing", 0);
             break;
              }
        }
 				me->receive_damage("jing", jing_cost );    
				me->add("learned_points", 1);

			}
			if (pertimes>0)
			{
				for (i=0;i<pertimes;i++)
				{
// 學習速度 = 後天悟性加上先天悟性的和的一半，加武功學習補償。
// 未定義學習補償的技能，默認學習補償爲10。
					improve_points = (me->query_int()+me->query("int"))/2;
					if(SKILL_D(skill)->learn_bonus())
						improve_points += SKILL_D(skill)->learn_bonus();
					else improve_points += 10;
// 調整向師父學習技能的速度，加重對叛師的懲罰。
					improve_points = improve_points / (me->query("betrayer") + 1);
					if (improve_points < 15) improve_points = 15;
					improve_points = random(improve_points);
// 對師傅傳授產生誤解的比率。== 0時候誤解。
//				if(random(SKILL_D(skill)->success()) )
						me->improve_skill(skill, improve_points);
				}
				if(skill_name = SKILL_D(skill)->query_skill_name(my_skill))
	 				printf("你聽了%s的指導，對「%s」這一招似乎有些心得。\n", ob->name(), skill_name);
				else
					printf("你聽了%s的指導，似乎有些心得。\n", ob->name());
        if (pertimes < times)
         return notify_fail("但是你今天太累了，學習了" + chinese_number(pertimes) +"次以後只好先停下來。\n");
			}
			else
				return notify_fail("你今天太累了，結果什麼也沒有學到。\n");
	return 1;
}

int help(object me)
{
	write(@HELP
指令格式 : learn|xue <某人> <技能> <次數>

    這個指令可以讓你向別人請教有關某一種技能的疑難問題，當然，你
請教的對象在這項技能上的造詣必須比你高，而你經由這種方式學習得來
的技能也不可能高於你所請教的人，然而因爲這種學習方式相當於一種「
經驗的傳承」，因此學習可以說是熟悉一種新技能最快的方法。

    通常，一個人剛學到一種新技能是不會有什麼疑難問題的，而是經由
實際上的應用中遭遇問題，這些問題對於學習一種新技能的過程是很重要
的，尤其是各種作爲其他技能基礎的基本技能，更需要經由「發現問題—
解決問題」的過程才能得到較好的效果因此我們將這種發現問題的過程用
「潛能」的觀念表示，一個人能夠自己發現某些問題，表示他（她）有解
決這項問題的潛能，當你具有這樣的潛能時就可以利用這個指令來向其他
人請教，而獲得進步。

(PS. 潛能還有其他更廣義的定義，這裏只是其中之一 )

    此外學習也需要消耗一些精力，而消耗的精力跟你自己、與你學習對
象的悟性有關。

    至於如何知道你能從對方學到什麼技能，如果對方是你的師父，可以
用 skills 指令直接查看，如果不是你的師父，那麼通常會有其他的提示，
你只好自己想辦法。

其他相關指令 : apprentice, practice, skills, study
HELP
	);
	return 1;
}
