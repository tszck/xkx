// Room: /d/chengdu/nanjie.c
// Last Modifyed by Winder on Jan. 4 2002

inherit ROOM;

void create()
{
	set("short", "南大街");
	set("long", @LONG
你走在南大街的最南端，道路兩旁栽種着枝粗葉茂的梧桐，路面被
打掃得乾乾淨淨。來來往往的都是些兵勇和官員，偶爾走過來幾個平民
百姓。西邊是一座古樸的祠堂，香火繚繞，遊人絡繹不絕，那就是川人
所共同敬仰的武侯祠。東面有個製作精緻的石拱橋。
LONG	);
	set("outdoors", "chengdu");
	set("exits", ([
		"east"      : __DIR__"gongqiao",
		"west"      : __DIR__"wuhoucigate",
		"north"     : __DIR__"nanjie2",
		"south"     : __DIR__"southgate",
		"southwest" : __DIR__"cai",
	]));
	set("objects", ([
		__DIR__"npc/qigai" : 2,
	]));
	set("coor/x", -8050);
	set("coor/y", -3030);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

