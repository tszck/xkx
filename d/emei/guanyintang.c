//Room: guanyintang.c 觀音堂
//Date: Oct. 2 1997 by That

inherit ROOM;

void create()
{
      set("short","觀音堂");
      set("long",@LONG
觀音堂高踞坡崗，近臨危崖，環境幽靜，四周樹木蓊鬱，悅目賞心。傳說
入山於此，解脫塵凡；出山於此，解脫險阻，又故名解脫庵。進山的人在此焚
香洗心，入山方可化險爲夷，步步平安。這裏東下可達伏虎寺，西上行約二里
可到歸雲閣。
LONG);
      set("exits",([ /* sizeof() == 1 */
          "eastdown"  : __DIR__"jietuopo",
          "westup"    : __DIR__"guiyunge",
      ]));
      set("outdoors", "emei");
      set("no_clean_up", 0);
	set("coor/x", -6070);
	set("coor/y", -1040);
	set("coor/z", 40);
	setup();
      replace_program(ROOM);
}