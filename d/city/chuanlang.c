// Room: /yangzhou/chuanlang.c
// Last Modified by Winder on Jul. 20 2000

inherit ROOM;

void create()
{
	set("short", "穿廊");
	set("long", @LONG
左右院內略略有幾點山石，山下為洞室，山前有池水。隔水望去，
有一種無限幽深的感覺。池水深莫可測，偶然有魚來遊，倏忽而沒。穿
廊上吊着一些個籠子，籠着各色禽鳥。穿廊的西壁，嵌有《顏魯公三表
》，隨讀隨行，碑盡而身轉，只見盡頭有廳，顏以額「梅船軒」。
LONG );
	set("outdoors", "yangzhouw");

	set("exits", ([
		"south" : __DIR__"menting",
		"north" : __DIR__"meichuanxuan",
	]));
	set("objects", ([
		__DIR__"npc/yahuan" : 1,
	]));
	set("coor/x", -11);
	set("coor/y", -49);
	set("coor/z", 0);
	set("no_quest",1);
	setup();
	replace_program(ROOM);
}