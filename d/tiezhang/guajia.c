// Room: /d/tiezhang/guajia.c
// Last Modified by winder on Nov. 17 2000

#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
	set("short", GRN"瓜架"NOR);
	set("long", @LONG
轉過一個小彎，忽然眼前一綠，面前是一片很大的瓜架。在高大的
木架旁，種植着一些蔬菜和瓜類，架子上已爬滿了各種植物，從茂密的
葉子中，垂下各種已經成熟的果實，絲瓜，苦瓜，葫蘆....還有一些叫
不出名稱的瓜果也纏雜在其中。
LONG	);
	set("outdoors", "tiezhang");
	set("exits", ([ /* sizeof() == 2 */
		"southeast" : __DIR__"shuijing",
		"west"      : __DIR__"guangchang",
	]));
	set("objects", ([
		CLASS_D("tiezhang")+"/qqzhang" : 1,
	]));
	set("hulu_count", 5);
	set("coor/x", -2030);
	set("coor/y", -1970);
	set("coor/z", 20);
	setup();
}
void init()
{
	add_action("do_zhai","zhai");
}

int do_zhai(string arg)
{
	object me = this_player();
	object ob;

	if (me->query_temp("marks/摘1") )
		return notify_fail("你已經摘過了，不要這麼貪心！\n");

	if (!arg || (arg != "hulu" && arg != "葫蘆"))
	{
		if (query("hulu_count") < 1)
		{
			message_vision("$N撥開枝葉找來找去，發現葫蘆已經被別人摘沒了！\n",this_player());
			return 1;
		}
		return notify_fail("你想摘什麼？\n");
	}
	else
	{
		write("你踮起腳尖，從架子上摘下了一個葫蘆。\n");
		this_player()->set_temp("marks/摘1", 1);

		ob=new("/d/emei/obj/qingshui-hulu");
		ob->move(this_player());
		add("hulu_count", -1);

		return 1;
	}
}
