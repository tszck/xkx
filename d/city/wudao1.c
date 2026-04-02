// Room: /city/wudao1.c
// Date: Feb.28 1998 by Java
#include <ansi.h>
inherit ROOM;
string look_gaoshi();
void create()
{
	set("short", "武道場");
	set("long", @LONG
這裏是三面環山，只有北面有條出口的一坪山間平地。山坡山陣陣
松濤嘩嘩作響，山腳下的平地綠草如茵，中間已經架起了個擂臺，四周
一溜過去搭着涼棚，棚中桌椅杯盆俱全，看來比武大會快開始了。
    場中立有一面告示牌(gaoshi)。
LONG );
        set("outdoors", "yangzhouw");
	set("item_desc", ([
		"gaoshi" : (: look_gaoshi :),
	]));
	set("exits", ([
		"leitai"      : __DIR__"leitai",
		"southwest"   : __DIR__"wudao3",
		"northwest"   : __DIR__"wudao4",
	]));
	set("no_clean_up", 0);
	set("no_fight", "1");
	set("no_steal", "1");
	set("no_beg", "1");
	set("coor/x", -10);
	set("coor/y", -30);
	set("coor/z", 0);
	setup();
}

void init()
{
	add_action("do_quit","quit");
	add_action("do_quit","exit");

	add_action("do_quit","exercise");
	add_action("do_quit","dazuo");
	add_action("do_quit","exert");
	add_action("do_quit","yun");
	add_action("do_quit","learn");
	add_action("do_quit","xue");
	add_action("do_quit","respirate");
	add_action("do_quit","tuna");
	add_action("do_quit","perform");
	add_action("do_quit","persuade");
	add_action("do_quit","quanjia");
	add_action("do_quit","practice");
	add_action("do_quit","lian");
	add_action("do_quit","study");
	add_action("do_quit","du");
	add_action("do_quit","teach");
	add_action("do_quit","jiao");
}

int do_quit(string arg)
{
	write(this_player()->query("name")+"，折騰個啥勁兒呀，專心看比武吧！\n");
	return 1;
}
int valid_leave(object me, string dir)
{
 
//	if ((dir == "leitai") && (!me->query_temp("leitai_allow")) && !wizardp(me))
//		return notify_fail("還沒到你比武呢，別猴急上去。\n");
//	if ((dir == "leitai") && (me->query_temp("leitai_allow")))
	if (dir == "leitai")
	{
		me->delete_temp("leitai_allow");
		me->delete_temp("view_leitai");
		me->set("no_get", 1);
	}
        return ::valid_leave(me, dir);
}
string look_gaoshi()
{
	return 
HIR"\n\n                           
                 俠客行一百的比武大會
\n"HIY"
第一、每月的十五日晚十九時三十分舉行比武大會。比賽地點設在揚州
      西門外武道場。
第二、比賽分組進行，每組比賽正式開始之前欲參加比武者請向當值巫
      師報名。分組如下：
      二十歲以下組 經驗100萬以下組 經驗100萬~300萬組
      經驗300萬~500萬組 經驗500萬~1000萬組 經驗1000萬以上組
      如果某一組內只有一人報名參加，他就直接獲得該組冠軍。
第三、比武實行淘汰制。
      各組除決賽實行三局兩勝制外，均為一場定勝負，勝者進入下一
      輪；三局兩勝制，第一局比較兵器上的功夫，第二局在拳腳上決
      個高下，第三局自選。優勝者獲得該組冠軍。
第四、為使天下第一名實相符，允許使用現行所有武功，允許perform、
      powerup、enforce、poison等，但roar由於嚴重影響比武秩序，
      因此謝絕使用。違者停賽。
第五、比賽時所用兵器和防具請在擂臺上的兵器架上自行拿取，經研究，
      禁止使用自鑄兵器，禁止使用金絲甲、軟蝟甲、真絲寶甲，禁止
      使用傷害力超過50的兵器如敖拜匕首、倚天劍、伏魔刀等。
第六、比賽時請注意言行，犯眾怒者、違反現場巫師安排者，取消其一
      年比賽資格。
"HIG"                                      俠客行  敬啓
\n"NOR;
}