// abandon.c
// Modified by zeratul,2000.3.31

inherit F_CLEAN_UP;
#include <ansi.h>

mapping valid_skill = ([
/*
        "jiuyin-baiguzhao":  "九陰白骨抓",
        "bixie-jian":        "辟邪劍法",
        "zhengqijue":        "正氣訣",
*/
]);
int main(object me, string arg)
{
	int skill_lvl, lvl=0, i;
	string skill, *sname;
	mapping smap, pmap, skl;

	smap = me->query_skill_map();
	pmap = me->query_skill_prepare();
	if(arg == "all" && wizardp(me))
	{
		skl = me->query_skills();
		if(!sizeof(skl))
		{
			write("你目前並沒有學會任何技能。\n");
			return 1;
		}
		sname = sort_array( keys(skl), (: strcmp :) );
		write("你決定放棄學習所有技能。\n");
		for( i = sizeof(skl)-1; i >= 0; i--)
		{
			me->delete_skill(sname[i]);
		}
		for (i = sizeof(smap)-1; i >= 0; i --)
			me->map_skill(keys(smap)[i]);
		for (i = sizeof(pmap)-1; i >= 0; i -- )
			me->prepare_skill(keys(pmap)[i]);
		me->reset_action();
		return 1;
	}
	if(!arg || arg == "" || sscanf(arg, "%s %d", skill, lvl)!=2 &&
		sscanf(arg, "%s", skill)!=1)
		return notify_fail("你要放棄哪一項技能？\n");
	if( !undefinedp(valid_skill[skill]) )
		return notify_fail(to_chinese(skill)+"如附骨之蛆，讓你無法放棄！\n");
	skill_lvl = me->query_skill(skill,1);
	if( lvl <0 )
		return notify_fail("技能級別不能爲負。\n");
	if( lvl == skill_lvl && lvl>0)
		return notify_fail("你有問題啊。你不就是這級別麼？\n");
	if( lvl > skill_lvl || lvl > 800)
		return notify_fail("你這項技能並沒有學到這個級別。\n");
	if( undefinedp((me->query_skills())[skill]) )
		return notify_fail("你並沒有學過這項技能。\n");
	if ((int)skill_lvl >= 100)
  {
  	write(HIW"確定將"+to_chinese(skill)+"("+skill+")"+
           "從"+HIR+chinese_number(skill_lvl)+HIW+"級放棄到"+
           HIR+chinese_number(lvl)+HIW+"級？(y/n)\n"NOR
           );
  	input_to("check_input",1,me,skill,lvl);
  }
  else
  {
		if( !me->delete_skill(skill) )
	    	return notify_fail("你並沒有學過這項技能。\n");
  	write("你決定放棄繼續學習" + to_chinese(skill) + "。\n");
		if( lvl > 0 ) me->set_skill(skill, lvl);
// 增加如下語句，當完全放棄某一項技能時，自動從enable列表中刪除之，避免戰鬥中的Bad action。 Added by Spacenet@FXLT
		else 
		{
			for (i = sizeof(smap)-1; i >= 0; i --)
				if ((string)smap[keys(smap)[i]] == skill)
					me->map_skill(keys(smap)[i]);
// 放棄時也從prepare表中刪除，Added by zeratul
			for (i = sizeof(pmap)-1; i >= 0; i -- )
				if ( ( string ) values(pmap)[i] == skill )
					me->prepare_skill(keys(pmap)[i]);
			me->reset_action();
		}
  }
  return 1;
}
int check_input(string arg,object me,string skill,int lvl)
{
	int i;
	mapping smap, pmap/*, skl*/;

	smap = me->query_skill_map();
	pmap = me->query_skill_prepare();
	if (strsrch(arg,"y")>=0)
	{
		if( !me->delete_skill(skill) )
	    	return notify_fail("你並沒有學過這項技能。\n");
		if( lvl > 0 ) {
  		write(HIW"你決定放棄部分的" + to_chinese(skill)+"。\n"NOR);
			me->set_skill(skill, lvl);
		}
	// 增加如下語句，當完全放棄某一項技能時，自動從enable列表中刪除之，避免戰鬥中的Bad action。 Added by Spacenet@FXLT
		else {
		write(HIW"你決心盡棄所學之" + to_chinese(skill) + "。\n"NOR);
			for (i = sizeof(smap)-1; i >= 0; i --)
				if ((string)smap[keys(smap)[i]] == skill)
					me->map_skill(keys(smap)[i]);
	// 放棄時也從prepare表中刪除，Added by zeratul
			for (i = sizeof(pmap)-1; i >= 0; i -- )
				if ( ( string ) values(pmap)[i] == skill )
					me->prepare_skill(keys(pmap)[i]);
			me->reset_action();
		}
	return 1;
	}
	else
//  	write("你決定放棄繼續學習" + to_chinese(skill) + "。\n");
	return 1;
}
int help()
{
	write(@TEXT
指令格式：abandon | fangqi <技能名稱> [級別]

    這個指令用來完全或部分放棄一項你所學過的技能，如果不帶級別數這個
參數則表示是完全放棄一項技能，將這項技能從你人物的資料中刪除，如果你
以後還要練，必須從０開始重練，請務必考慮清楚。如果帶了級別數這個參數
則表示部分放棄某技能，放棄到哪一級。

    例如：ｆａｎｇｑｉ ｌｉｔｅｒａｔｅ ５０  表示放棄後只剩下５０
級讀書寫字，這個指令使用的場合通常是用來刪除一些不小心練出來的技能，
由於每個人有着不同的天賦，所修習的武功也不會相同。如果樣樣都學，到頭
來只會樣樣不精。

TEXT
	);
	return 1;
}