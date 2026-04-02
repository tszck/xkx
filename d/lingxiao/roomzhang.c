// Room: /d/lingxiao/roomzhang.c
// Last Modified by Winder on Jul. 15 2001

inherit ROOM;
void create()
{
	set("short","居室");
	set("long",@LONG 
走進這裏，出現在你眼前的是大大小小的藥罐。在這裏住的是凌霄
城的六代弟子張萬年，他爲人厚道，所以白自在放心地把管理凌霄城一
些稀世藥物的任務交給了他。不過據說他跟王萬仞向來交好，經常把一
些珍貴的藥酒給那傢伙喝。
LONG);
	set("exits",([ /* sizeof() == 1 */
		"north"  : __DIR__"zoulang2", 
	]));
	set("objects", ([  
		__DIR__"npc/zhang" : 1,
		__DIR__"obj/icesword" : 3,
	]));
	set("coor/x", -30990);
	set("coor/y", -8880);
	set("coor/z", 140);
	setup();
	replace_program(ROOM);
}

