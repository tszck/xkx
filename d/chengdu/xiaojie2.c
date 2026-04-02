// Room: /d/chengdu/xiaojie2.c
// Modifyed by Sir on Dec. 4 2001
// Last Modifyed by Winder on Dec. 24 2001

inherit ROOM;

void create()
{
	set("short", "小街");
	set("long", @LONG
這是一條青石板鋪成的小街，路面非常乾淨。朝北邊看，是一個釀
酒的小屋。東邊是一座兩層的樓閣，掛着“陳麻婆豆腐”的招簾，門額
上懸掛一方橫匾“麻到爲止”四字擦得閃閃發亮，乃是蘇軾的手筆。陣
陣辣椒香味撲鼻而來,讓你垂涎欲滴。
LONG	);
	set("outdoor","chengdu");
	set("exits", ([
		"west"      : __DIR__"gongqiao1",
		"southeast" : __DIR__"niangjiuwu",
		"northwest" : __DIR__"xiaojie1",
	]));
	set("no_clean_up", 0);
	set("coor/x", -8010);
	set("coor/y", -3030);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

