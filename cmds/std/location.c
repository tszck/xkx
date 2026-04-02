// location.c
inherit F_CLEAN_UP;

#include <ansi.h>



string *place_desc = ({
	"揚州城的武廟",
	"揚州城的富春茶社",
	"揚州城的武道場",
	"揚州城的飛雪堂",
	"揚州城的武館大廳",
	"揚州城的秦淮客寓",
	"北京城的客店",
	"成都城的錦城驛",
	"蘇州城的客店",
	"杭州城的天外天",
	"福州城的榕城驛",
	"蘭州城的順風客棧",
	"泉州城的鴻福樓",
	"大理城的客店",
	"長安城的雲來客棧",
	"江陵城的晴川客棧",
	"襄陽城的襄陽客棧",
	"無錫城的客店",
	"嶽陽城的牡丹樓",
	"揚州的十里長街",
	"杭州的青石大道",
	"杭州的蘇堤",
	"少林寺的松樹林",
	"武當山的林間小徑",
	"峨嵋山的九十九道拐",
	"崑崙山的崑崙山路",
	"華北的大驛道",
	"大理的官道"
});
int main(object me, string arg)
{
	object ob, where,tbg;
	mapping fam/*,fam2*/;
	int sp, dp, i, cost, count_lvl, bibo_lvl, placeno;
	string *dir, *place;

	seteuid(getuid());

	if( (!(fam = me->query("family")) || fam["family_name"] != "桃花島") )
		return notify_fail("只有桃花島入門弟子才能推算別人的所在！\n");
	if (me->is_busy())
		return notify_fail("你上一個動作還沒有完成！\n");
	if( !present("tie bagua", me))
		return notify_fail("沒有鐵八卦，恐怕沒法推算別人的所在！\n");

	tbg= present("tie bagua", me);
	if(tbg->query("ownmake")==1)
//	fam2 = me->query("weapon");
//	if(fam2["id"] == "tie bagua")
		return notify_fail("恐怕這個鐵八卦不行吧！\n");
	
	count_lvl = me->query_skill("count",1);
	bibo_lvl = me->query_skill("bibo-shengong",1);
	if( bibo_lvl < 30 && !wizardp(me))
		return notify_fail("你桃花島武功尚未入門，無法做出推算！\n");
	if( count_lvl < 30 && !wizardp(me))
		return notify_fail("你的陰陽八卦尚未純熟，無法推算別人的所在！\n");
	if ( !arg ) return notify_fail("你要推算誰的所在？\n");
	if ( present(arg, environment(me)) )
		return notify_fail("你要推算的人就在邊上，你不是有毛病吧？\n");
	ob = find_player(arg);
	if (!ob) ob = find_living(arg);
	if (!ob) return notify_fail("你要推算誰的所在？\n");
	if (wizardp(ob) && !wizardp(me))
		return notify_fail("你要推算誰的所在？\n");
	if ( ob == me )
		return notify_fail("你沒這麼笨吧，要別人告訴你自己在哪裏？\n");
	cost = me->query("max_jing")/(1+me->query_skill("count",1)/10) - 10;
	if ( me->query("jing") <= cost )
		return notify_fail("現在你太累了，無法去推算別人的所在。\n");

	message_vision( CYN"$N拿起一隻鐵八卦屏心凝氣，拇指依次掐向鐵八卦上子、醜、寅、卯、辰、巳、午、未、申、酉、戌、亥各個方位，細心推算起來……\n\n\n"NOR, me);
	message_vision("口中唸唸有詞，忽然臉露微笑: 有了！\n\n",me);
	me->start_busy(3);

	sp = count_lvl*10 + me->query("jing");
	dp = ob->query("kar")*5 + ob->query("jing")*2;

	tell_object(ob, HIB"你感覺心神不定，似乎有人在暗中窺視着你......\n"NOR);
	if ( random(sp) < random(dp)/2 )
		return notify_fail( "你又頹然坐下，搖了搖頭，說道：不對的！\n");

	me->receive_damage("jing", cost );
	where = environment(ob);
	if (!where) return notify_fail("這個人不知道在哪裏耶...\n");
	if (random(10) > 7)
	{
		printf("%s現在可能在%s。\n",
		(string)ob->name(), place_desc[random(sizeof(place_desc))]);
		return 1;
	}
	dir = get_dir("/d/");
	if ( random(sp) < random(dp) || count_lvl < 100)
	{
		for (i=0; i<sizeof(dir); i++)
			if (strsrch(file_name(where), "/"+dir[i]+"/") >= 0)
				return notify_fail(ob->name()+ "現在可能在"+to_chinese(dir[i])+"的某個地方！\n");
		return notify_fail( ob->name()+"現在在哪裏呢？不知道啊！\n");
	}
	if ( random(sp) < random(dp) || bibo_lvl < 100)
	{
		for (i=0; i<sizeof(dir); i++)
			if (strsrch(file_name(where), "/"+dir[i]+"/") >= 0)
			{
				place = get_dir("/d/"+dir[i]+"/");
				placeno = random(sizeof(place));
				if(strsrch(place[placeno], ".c") >= 0)
				{
					if(!( where = find_object("/d/"+dir[i]+"/"+place[placeno])))
						where = load_object("/d/"+dir[i]+"/"+place[placeno]);
					return notify_fail(ob->name()+ "現在可能在"+to_chinese(dir[i])+"的"+where->query("short")+"！\n");
				}
				else return notify_fail(ob->name()+ "現在可能在"+to_chinese(dir[i])+"的某個地方！\n");
			}
		return notify_fail( ob->name()+"現在在哪裏呢？不知道啊！\n");
	}
	for (i=0; i<sizeof(dir); i++)
		if (strsrch(file_name(where), "/"+dir[i]+"/") >= 0)
		{
			printf("%s現在可能在%s的%s。\n", ob->name(), to_chinese(dir[i]), where->query("short"));
			return 1;
		}
	return notify_fail("這個人不知道在哪裏耶...\n");
}

int help(object me)
{
	write(@HELP
指令格式: location <玩家的 ID>

    這個指令是桃花島弟子用來得知玩家目前所在的位置。

HELP
	);
	return 1;
}
