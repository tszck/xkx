inherit ROOM;

void create()
{
        set("short", "西大街");
        set("long", @LONG
開封府內西面的主要交通要道，街道兩邊店鋪林立，行人
車馬如梭。小商販們挑着擔子來回吆喝。此地向東就是相國寺
的放生池，再向北過去不遠，就能見到延慶觀的大門了。
LONG
        );
        set("no_clean_up", 0);
        set("exits", ([
  		"north" : __DIR__"wroad1",
  		"eastup" : __DIR__"fangsheng",
	]));
        set("outdoors", "kaifeng");

        setup();
        replace_program(ROOM);
}
