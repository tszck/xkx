// study.c
// 本命令沒有考慮learn_bonus和practice_bonus。待考慮。
inherit F_CLEAN_UP;

#include <skill.h>


void create() { seteuid(getuid()); }

int main(object me, string arg)
{
	object where = environment(me);
	object ob;
	string zhao_name, book_name;
	string *args;
	mapping skill;
	int my_skill, cost, times, i/*, success=0*/;
	int j;

	if (where->query("pigging"))
		return notify_fail("你還是專心拱豬吧！\n");
	if (where->is_chat_room())
    return notify_fail("這裏禁止練功。\n");
	if (me->is_busy())
		return notify_fail("你現在正忙着呢。\n");
	if( me->is_fighting() )
		return notify_fail("你無法在戰鬥中專心下來研讀新知！\n");
//	if(sscanf(arg, "%s %d", book_name, times)!=2 )
//		return notify_fail("指令格式：study|du <書名> <次數>\n");
//取書名
	if (! arg || (i = sizeof(args = explode(arg, " "))) < 1)
         return notify_fail("指令格式：study|du <書名> <次數>\n");
        i--;
        if (i >= 1 && sscanf(args[i], "%d", times) && times)
                i--;
        else
                times = 1;
        if (args[i] == "with" && i >= 1)
                i--;
        book_name = implode(args[0..i], " ");


	if (times < 1 || times > 100)
		return notify_fail("讀書次數最少一次，最多不能超過一百次。\n");
	if(!objectp(ob = present(book_name, me)) )
		return notify_fail("沒這本書可讀啊？\n");
	if( !mapp(skill = ob->query("skill")) )
		return notify_fail("你無法從這樣東西學到任何東西。\n");
	if( !me->query_skill("literate", 1) )
		return notify_fail("你是個文盲，先學點文化(literate)吧。\n");

	message("vision", me->name() + "正專心地研讀" + ob->name() + "。\n", environment(me), me);
	if( (int)me->query("combat_exp") < skill["exp_required"] )
	{
		write("你的實戰經驗不足，再怎麼讀也沒用。\n");
		return 1;
	}
	notify_fail("以你目前的能力，還沒有辦法學這個技能。\n");
	if( !SKILL_D(skill["name"])->valid_learn(me) ) 
	return 0;
	cost = skill["jing_cost"] + skill["jing_cost"] 
		* (skill["difficulty"] - (int)me->query("int"))/20;
	if (cost < 10) cost = 10; // minimum cost
	if( me->query_skill(skill["name"], 1) > skill["max_skill"] )
	{
		return notify_fail("你研讀了一會兒，但是發現上面所說的對你而言都太淺了，沒有學到任何東西。\n");
	}
	if( me->query_skill(skill["name"], 1) < skill["min_skill"] )
	{
		return notify_fail("你研讀了一會兒，但是發現上面所說的對你而言都太深奧了，毫無收穫。\n");
	}
	if( !me->query_skill(skill["name"], 1)) me->set_skill(skill["name"], 0);
	my_skill = me->query_skill(skill["name"], 1);
	if( (string)SKILL_D(skill["name"])->type()=="martial" &&
			my_skill * my_skill * my_skill / 10 > (int)me->query("combat_exp") )
		{
			return notify_fail("也許是缺乏實戰經驗，你對"+ob->name()+"上面所說的東西總是無法領會。\n");
		}
		if (!me->query("env/auto_regenerate") && 
        				me->query("jing")< cost * times)
							return notify_fail("你現在過於疲倦，無法專心下來研讀新知。\n");
	for (i = 0; i < times; i++)
			{        	

			if ((int)me->query("jing") > cost)
            me->receive_damage("jing", cost );
      else if (me->query("env/auto_regenerate") &&
                SKILL_D("force/regenerate")->exert(me, me))
              {
                        // try to regenerate & learn again
                        write("你覺得精神好了一些，繼續讀書。\n");
                        i--;
                        continue;
              } else
              {
                        me->set("jing", 0);
                        break;
              }
			}
	if (!i) 
		return notify_fail("你現在太累了，結果一行也沒有看下去。\n");
	if(zhao_name = SKILL_D(skill["name"])->query_skill_name(my_skill))
				printf("你研讀了"+chinese_number(i)+"行有關%s的技巧，對「%s」這一招似乎有些心得。\n", to_chinese(skill["name"]), zhao_name);
			else
				printf("你研讀了"+chinese_number(i)+"行有關%s的技巧，似乎有點心得。\n", to_chinese(skill["name"]));

	for (j=0;j<i;j++)
	{
//原來的速度			me->improve_skill(skill["name"], (int)me->query_skill("literate", 1)/5+1);   
     me->improve_skill(skill["name"], (int)me->query_skill("literate", 1)/3+1);
	}
//	if (i < times)
//	return notify_fail("你現在過於疲倦，無法專心下來研讀新知。\n");
	return 1;
}

int help(object me)
{
	write( @HELP
指令格式: study | du <物品名稱> <次數>

    這個指令使你可以通過閱讀祕笈或其他物品自學某些技巧，但前
提是: 你不能是個『文盲』。怎樣脫盲？去學文化啦！

see also : learn
HELP
	);
	return 1;
}