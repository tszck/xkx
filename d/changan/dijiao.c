// /d/changan/dijiao.c

inherit  ROOM;

void  create  ()
{
	set  ("short",  "地窖");
	set  ("long",  @LONG
滿窖裏漫着酒池，二百多個酒罈子都成了破瓷塊，你終於明白停業
的原因了。原來田伯光要巴結令狐沖，從這抱走了兩壇酒送上華山。臨
走時見地窖中尚有二百餘壇，心想長安城中的達官貴人、凡夫俗子，只
須腰中有錢，便能上‘謫仙樓’去喝到這樣的美酒，又如何能顯得華山
派令狐大俠的矯矯不羣，與衆不同？因此上乒乒乓乓，希裏花拉，地窖
中酒香四溢，酒漲及腰。
LONG);
	set("exits",  ([  //sizeof()  ==  4
		"up"  :  __DIR__"jiulou",
	]));
	set("no_clean_up", 0);
	set("coor/x", -5030);
	set("coor/y", 1020);
	set("coor/z", -10);
	setup();
	replace_program(ROOM);
}
