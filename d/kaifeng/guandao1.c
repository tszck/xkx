// /kaifeng/guandao1.c
// Last modified by winder 2003.10.20

inherit ROOM;

void create()
{
	set("short", "官道");
	set("long", @LONG
這是條連接開封府與中州府的官道，由於這條路治安較好行人也不
少。西面通向開封，東面通向南陽。
LONG);
	set("exits", ([
  		"east"      : __DIR__"tokaifeng",
  		"northwest" : __DIR__"shulin",
	]));
        set("outdoors", "kaifeng");
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}
