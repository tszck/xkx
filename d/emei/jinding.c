//Room: jinding.c 金頂
//Date: Oct. 2 1997 by That

inherit ROOM;

void create()
{
      set("short","金頂");
      set("long",@LONG
這就是峨嵋山的主峯金頂了。此峯聳立大地，高入雲表，秀麗而又壯美，
李白讚頌它：『青冥倚天開，彩錯疑畫出。』登上金頂，視野豁然開朗，鳥瞰
腳下，但見羣峯湧綠疊翠，三江如絲如帶；回首遠眺，則見大雪山橫亙天際，
貢嘎山直插蒼穹。
LONG);
      set("outdoors", "emei");
      set("exits",([ /* sizeof() == 1 */
          "northdown"  : __DIR__"wanxingan",
          "southwest"  : __DIR__"woyunan", 
          "south"      : __DIR__"huacangan",
      ]));
      set("no_clean_up", 0);
	set("coor/x", -6220);
	set("coor/y", -1140);
	set("coor/z", 190);
	setup();
      replace_program(ROOM);
}