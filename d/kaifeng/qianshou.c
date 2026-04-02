// /kaifeng/qianshou.c
// Last modified by winder 2003.10.20

inherit ROOM;

void create()
{
	set("short", "千手千眼佛殿");
	set("long", @LONG
這座佛殿中供奉的是千手千眼觀音，據説觀音菩薩普渡眾生，化身
萬千。你仔細看去，只見佛像伸出長長短短的手臂每個手掌中心都有隻
眼睛。意思是警告你“我眼睛多，什麼都能夠注意到，我手多，什麼都
能管到，可別作壞事。”
LONG
	);
	set("exits", ([
		"west" : __DIR__"fangsheng",
		"east" : __DIR__"houyuan",
	]));
	set("objects", ([
		__DIR__"npc/oldwomen" : 1,
		__DIR__"npc/obj/guanyin" : 1,
	]));

	setup();
	replace_program(ROOM);
}
