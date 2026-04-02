// Room: /d/taohua/taohua3.c
// Last Modified by winder on Nov. 17 2000

inherit ROOM;
#include <ansi.h>
int do_look(string arg);

void create()
{
	int thd1, thd2, thd3, thd4;

	thd1 = random(4) + 1;
	thd2 = random(4) + 1;
	thd3 = random(4) + 5;
	thd4 = random(4) + 1;
	set("short", "桃花陣");
	set("long", @LONG
這裏是一片桃花的海洋。四周一望無際，全是盛開的桃花。微風拂
過，落英繽紛。周圍靜悄悄的。遠處偶爾傳來一聲鳥叫。你心中不禁慌
亂起來：還是早點出去的好。
LONG
	);

	set("exits", ([
		"east" : __DIR__"taohua" + thd1,
		"west" : __DIR__"taohua" + thd2,
		"south" : __DIR__"taohua" + thd3,
		"north" : __DIR__"taohua" + thd4,
	]));
	set("no_drop","1");
	set("coor/x", 9010);
	set("coor/y", -3090);
	set("coor/z", 0);
	setup();
}

void init()
{
	object ob=this_player();

	if (ob->query_temp("step_count") > 99) {
		ob->delete_temp("step_count");
		write("你在陣中累得精疲力盡，終因體力不支而昏了過去！\n");
		write("迷迷胡胡中似乎有人把你抬出了陣，彷彿有個威嚴的聲音喝道：“扔到海里去”。\n");
		ob->unconcious();
		ob->move(__DIR__"shore", 1);
		message("vision", "忽然一個大潮湧了過來，將一個被水泡得半死的傢伙衝到了岸邊。\n", environment(ob), ob);
		return;
	}
	ob->add_temp("step_count", 1);
	add_action("do_look", "look");
	add_action("do_look", "l");
}

int do_look(string arg)
{
 
	if (arg == "east" || arg == "west" || arg == "south" || arg == "north")
	{
		write(HIC"桃花陣"NOR" -
    這裏是一片桃花的海洋。四周一望無際，全是盛開的桃花。微風拂
過，落英繽紛。周圍靜悄悄的。遠處偶爾傳來一聲鳥叫。你心中不禁慌
亂起來：還是早點出去的好。
    這裏明顯的出口是 east、north、south 和 west。\n");
		return 1;
	}
	return 0;
}
