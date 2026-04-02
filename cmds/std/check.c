// check.c
inherit F_CLEAN_UP;

#include <ansi.h>



/*string *skill_level_desc = ({
	BLU "初學乍練" NOR,
	HIB "粗通皮毛" NOR,
	HIB "半生不熟" NOR,
	HIB "馬馬虎虎" NOR,
	HIB "駕輕就熟" NOR,
	CYN "出類拔萃" NOR,
	CYN "神乎其技" NOR,
	CYN "出神入化" NOR,
	HIC "登峯造極" NOR,
	HIC "一代宗師" NOR,
	HIW "深不可測" NOR
});

string *knowledge_level_desc = ({
	BLU "新學乍用" NOR,
	HIB "初窺門徑" NOR,
	HIB "略知一二" NOR,
	HIB "馬馬虎虎" NOR,
	HIB "已有小成" NOR,
	CYN "心領神會" NOR,
	CYN "瞭然於胸" NOR,
	CYN "豁然貫通" NOR,
	HIC "舉世無雙" NOR,
	HIC "震古鑠今" NOR,
	HIW "深不可測" NOR
});
*/
string *skill_level_desc = ({
	BLU"不堪一擊",BLU"毫不足慮",BLU"不足掛齒",BLU"初學乍練",BLU"勉勉強強",
	HIB"初窺門徑",HIB"初出茅廬",HIB"略知一二",HIB"普普通通",HIB"平平淡淡",
	CYN"平淡無奇",CYN"粗通皮毛",CYN"半生不熟",CYN"馬馬虎虎",CYN"略有小成",
	HIC"已有小成",HIC"鶴立雞羣",HIC"駕輕就熟",HIC"青出於藍",HIC"融會貫通",
	HIG"心領神會",HIG"爐火純青",HIG"瞭然於胸",HIG"略有大成",HIG"已有大成",
	YEL"豁然貫通",YEL"出類拔萃",YEL"無可匹敵",YEL"技冠羣雄",YEL"神乎其技",
	HIY"出神入化",HIY"非同凡響",HIY"傲視羣雄",HIY"登峯造極",HIY"無與倫比",
	RED"所向披靡",RED"一代宗師",RED"精深奧妙",RED"神功蓋世",RED"舉世無雙",
	WHT"驚世駭俗",WHT"撼天動地",WHT"震古鑠今",WHT"超凡入聖",WHT"威鎮寰宇",
	HIW"空前絕後",HIW"天人合一",MAG"深藏不露",HIM"深不可測",HIR"返璞歸真" 
});

string *knowledge_level_desc = ({
	BLU"新學乍用",BLU"初窺門徑",HIB"略知一二",HIB"半生不熟",
	CYN"馬馬虎虎",CYN"已有小成",HIC"融會貫通",HIC"心領神會",
	GRN"瞭然於胸",GRN"豁然貫通",YEL"非同凡響",YEL"舉世無雙",
	HIY"震古鑠今",RED"無與倫比",WHT"超凡入聖",HIW"空前絕後",
});
string skill_level(string, int);

int main(object me, string arg)
{
	object ob, man, *all;
	mapping fam, skl, lrn, map;
	string *sname, *mapped;
	int sp, dp, i, cost, check_lvl, skl_lvl, adj_lvl;
/* adj_lvl是誤差級別。等於100-checking級別 */

	seteuid(getuid());

	all = all_inventory(environment(me));
	for(i=0; i<sizeof(all); i++)
	{
		if( living(all[i]) && !userp(all[i]) ) man = all[i];
	}
	if ( (!(fam = me->query("family")) || fam["family_name"] != "丐幫") )
		return notify_fail("只有乞丐才能打探別人的技能！\n");
	if ( !objectp(man) )
		return notify_fail("周圍沒人能幫你去了解別人的技能！\n");
	check_lvl = me->query_skill("checking", 1);
	if ( check_lvl < 10 )
		return notify_fail("你的打探本領尚未純熟，無法瞭解別人的技能！\n");
	if(check_lvl < 150) adj_lvl = 150 - check_lvl;
	else adj_lvl = 0;

	if ( !arg ) return notify_fail("你要打聽誰的技能？\n");
	if ( present(arg, environment(me)) )
		return notify_fail("你要打聽的人就在邊上，在這裏問不大妥當吧？\n");
	ob = find_player(arg);
	if (!ob) ob = find_living(arg);
	if (!ob) return notify_fail("你要打聽誰的技能？\n");
	if (!me->visible(ob))
		return notify_fail("你要打聽誰的技能？\n");
	if ( ob == me )
		return notify_fail("你沒這麼笨吧，要別人告訴你自己的技能？\n");
	cost = me->query("max_jing")/(check_lvl/10) - 10;
	if ( me->query("jing") <= cost )
		return notify_fail("現在你太累了，無法去打聽別人的技能。\n");

	tell_object(me, "你走上前去，小心翼翼地向" + man->name() + "打聽關於" + ob->name() + "的情況 ...\n\n");
	message("vision", "只見" + me->name() + "陪着笑臉跟" + man->name() + "説着話，好象在打聽些什麼。\n\n", environment(me), ({ me, man }) );

	sp = check_lvl*10+me->query("kar")*5+me->query("jing")+man->query("jing");
	dp = ob->query("kar")*5 + ob->query("jing")*2;
	if ( random(sp) < random(dp) && !wizardp(ob))
		return notify_fail(man->name() + "搖了搖頭，説道：這事我可不清楚，" + RANK_D->query_respect(me) + "還是去向別人打聽一下吧！\n");
	me->receive_damage("jing", cost );
	skl = ob->query_skills();
	if(!sizeof(skl) || ob->query("yinshi"))
	{
		write(man->name() + "告訴你： " + ob->name() + "目前並沒有學會任何技能。\n");
		return 1;
	}
	write(man->name()+"告訴你："+ob->name()+"目前所學過的技能大概有：\n\n");
	sname = sort_array( keys(skl), (: strcmp :) );
	
	map = ob->query_skill_map();
	if( mapp(map) ) mapped = values(map);
	if( !mapped ) mapped = ({});

	lrn = ob->query_learned();
	if( !mapp(lrn) ) lrn = ([]);
	 
	i = random(sizeof(skl));
	skl_lvl = skl[sname[i]]-adj_lvl/2+random(adj_lvl);
	if(skl_lvl < 0) skl_lvl = random(10) + 1;
	

	printf("%s%s%-40s"NOR" - %-10s"NOR" %3d/%5d\n", 
		(lrn[sname[i]]>=(skl[sname[i]]+1)*(skl[sname[i]]+1)) ? HIM : "",
		(member_array(sname[i], mapped)==-1? "  ": "□"),
		to_chinese(sname[i]) + " (" + sname[i] + ")",
		skill_level(SKILL_D(sname[i])->type(), skl[sname[i]]),
		skl_lvl, (int)lrn[sname[i]],
	);
	if ( me->query("combat_exp") > (check_lvl*check_lvl*check_lvl)/10)
	{
		me->improve_skill("checking", random(me->query("int")));
	}

	write("\n");
	return 1;
}

string skill_level(string type, int level)
{
	int grade;


	switch(type) {
		case "knowledge":
	grade = level / 30;
			if( grade >= sizeof(knowledge_level_desc) )
				grade = sizeof(knowledge_level_desc)-1;
			return knowledge_level_desc[grade];
		default:
	grade = level / 10;
			if( grade >= sizeof(skill_level_desc) )
				grade = sizeof(skill_level_desc)-1;
			return skill_level_desc[grade];
	}
}

int help(object me)
{
	write(@HELP
指令格式 : check|dating [<某人>]

    這個指令可以讓你打聽別人所學過的技能。但是如果你技能不夠精熟
的話，打聽結果未免有偏差。

    你也可以指定一個和你有師徒關係的對象，用 skills|cha 可以查知
對方的技能狀況。

    此命令為丐幫弟子專用，並需學習相應的技能。

HELP
	);
	return 1;
}
