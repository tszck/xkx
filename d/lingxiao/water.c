// Room: /d/lingxiao/water.c
// Last Modified by Winder on Jul. 15 2001

#include <ansi.h>
inherit ROOM;
int do_dive(string arg);
void create()
{
	set("short", "雪山溫泉");
	set("long", @LONG
這裏是兩個山道盆地之間，有一股噴泉正在嘶嘶噴水，灼熱的水花
被風吹散，在月光下形成一團團白色的花環。在這雪山之上，居然還有
此等令人愜意之處，亦不由讓人感嘆造物之神奇。碧波綠水中，飄蕩着
朵朵雪蓮花瓣，片片雪花飄然而下，離水面有數寸，便即紛紛化爲白霧
而散。在這生命絕跡的大雪山之上，惟有這裏，纔有綠樹、紅花、青草。
一個少女在溫泉畔凝望落花，似有無限心事。
LONG );
	set("resource/water", 1);
	set("objects", ([
		__DIR__"npc/a-xiu" : 1,
	]) ); 
	set("resource/water", 1);
	set("exits", ([ 
		"east" :__DIR__"sroad6",
	]));
	set("coor/x", -31010);
	set("coor/y", -8950);
	set("coor/z", 110);
	setup(); 
} 
void init()
{       
	add_action("do_dive","dive");
}
int do_dive(string arg)
{
	object me = this_player();

	if ((arg !="lake" || !arg))
		return notify_fail("你要潛什麼？\n");
	if ((int)me->query_skill("force") < 100 )
	{ 
		message_vision("$N剛下水不久，就發現愈往下潛，水壓愈大，忍了一會，\n終於再也忍受不住，猛地竄了上來。\n", me);
	} 
	else 
	{
		message_vision("$N鼓足勇氣，往下潛去，只覺壓力越來越大，$N強運內力，奮力支持，向下潛去，\n只聽水中嘩啦一聲，就平靜下來了。\n", me); 
		me->move(__DIR__"wave1"); 
	} 
	return 1;
}

