// skills.c
inherit F_CLEAN_UP;

#include <ansi.h>



string *skill_level_desc = ({
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

string skill_level(string, int);

int main(object me, string arg)
{
	object ob;
	mapping skl, lrn, map;
	string *sname, *mapped, str;
	int i;

	seteuid(getuid());

	if(!arg)
		ob = me;
	else{
		ob = present(arg, environment(me));
//        if ( ob->query("SPSKILLS",1)  ) return ob->skills();		 
		if (!ob) ob = find_player(arg);
		if (!ob) ob = find_living(arg);
		if (!ob) return notify_fail("你要察看誰的技能？\n");
	}

	skl = ob->query_skills();
	if(!sizeof(skl)) {
		write( (ob==me ? "你" : ob->name()) + "目前並沒有學會任何技能。\n");
		return 1;
	}
	write( (ob==me ? "你" : ob->name()) +"目前所學過的技能：\n\n");
	sname  = sort_array( keys(skl), (: strcmp :) );
	
	map = ob->query_skill_map();
	if( mapp(map) ) mapped = values(map);
	if( !mapped ) mapped = ({});

	lrn = ob->query_learned();
	if( !mapp(lrn) ) lrn = ([]);
	str = "\n";
	for(i=0; i<sizeof(skl); i++) {
//		printf("%s%s%-40s" NOR " - %-10s %3d/%5d\n", 
//			(lrn[sname[i]] >= (skl[sname[i]]+1) * (skl[sname[i]]+1)) ? HIM : "",
//			(member_array(sname[i], mapped)==-1? "  ": "□"),
//			to_chinese(sname[i]) + " (" + sname[i] + ")",
//			skill_level(SKILL_D(sname[i])->type(), skl[sname[i]]),
//			skl[sname[i]], (int)lrn[sname[i]],
//		);
		str += sprintf("%s%s%-40s" NOR " - %-10s %3d/%5d\n", 
			(lrn[sname[i]] >= (skl[sname[i]]+1) * (skl[sname[i]]+1)) ? HIM : "",
			(member_array(sname[i], mapped)==-1? "  ": "□"),
			to_chinese(sname[i]) + " (" + sname[i] + ")",
			skill_level(SKILL_D(sname[i])->type(), skl[sname[i]]),
			skl[sname[i]], (int)lrn[sname[i]], );
	}
//	write("\n");
	str += sprintf("\n");
	me->start_more(str);
	return 1;
}

string skill_level(string type, int level)
{
	int grade;

    grade = level / 20;

	switch(type) {
		case "knowledge":
			if( grade >= sizeof(knowledge_level_desc) )
				grade = sizeof(knowledge_level_desc)-1;
			return knowledge_level_desc[grade];
		default:
			if( grade >= sizeof(skill_level_desc) )
				grade = sizeof(skill_level_desc)-1;
			return skill_level_desc[grade];
	}
}

int help(object me)
{
	write(@HELP
指令格式 : skills|cha [<某人>]

這個指令可以讓你(你)查詢所學過的技能。

你也可以指定一個和你有師徒關係的對象，用 skills 可以查知對方的技能狀況。

巫師可以查詢任何人或 NPC 的技能狀況。

HELP
    );
    return 1;
}
