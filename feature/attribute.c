// attribute.c
// From ES2
// Modified by Xiang for XKX (12/15/95)
// Modified by Winder for XKX100 (09/10/2000)

#include <dbase.h>
#include <skill.h>

// 膂力 -- 出手重
int query_str()
{
	int improve = query_skill("unarmed", 1) / 10;

	if ( query_skill("leg", 1) || query_skill("strike", 1) ||
		query_skill("finger", 1) || query_skill("cuff", 1) ||
		query_skill("hand", 1) || query_skill("claw", 1))
	{
		if ( query_skill("leg", 1) >= improve * 10)
			improve = (int)query_skill("leg", 1) / 10;
		if ( query_skill("strike", 1) >= improve * 10 )
			improve = (int)query_skill("strike", 1) / 10;
		if ( query_skill("finger", 1) >= improve * 10)
			improve = (int)query_skill("finger", 1) / 10;
		if ( query_skill("cuff", 1) >= improve * 10)
			improve = (int)query_skill("cuff", 1) / 10;
		if ( query_skill("hand", 1) >= improve * 10)
			improve = (int)query_skill("hand", 1) / 10;
		if ( query_skill("claw", 1) >= improve * 10)
			improve = (int)query_skill("claw", 1) / 10;
	}
	return (int)query("str") + query_temp("apply/strength") + improve;
}

// 悟性 -- 學習和讀書快
int query_int()
{
	return (int)query("int") + query_temp("apply/intelligence") +
		(int)query_skill("literate", 1) / 10;
}

// 根骨 -- 氣血恢復快且長大時氣血上限增量高
int query_con()
{
	return (int)query("con") + query_temp("apply/constitution") +
		(int)query_skill("force", 1) / 10;
}

// 身法 -- 躲避快
int query_dex()
{
	return (int)query("dex") + query_temp("apply/dexerity") +
		(int)query_skill("dodge", 1) / 10;
}

// 耐力 -- 內力恢復快
int query_sta()
{
	return (int)query("sta") + query_temp("apply/stamina")+
		(int)query_skill("parry", 1) / 10;
}

// 靈性 -- 能學更多的武功，且速度也快
int query_spi()
{
	int improve = query_skill("buddhism", 1) / 10;

	if ( query_skill("buddhism", 1) || query_skill("mahayana", 1) ||
		query_skill("lamaism", 1) || query_skill("taoism", 1) ||
		query_skill("ziyunyin",1) || query_skill("zhengqijue",1)||
		query_skill("poison"),1)
	{
		if ( query_skill("buddhism", 1) >= improve * 10 )
			improve = (int)query_skill("buddhism", 1) / 10;
		if ( query_skill("mahayana", 1) >= improve * 10)
			improve = (int)query_skill("mahayana", 1) / 10;
		if ( query_skill("lamaism", 1) >= improve * 10)
			improve = (int)query_skill("lamaism", 1) / 10;
		if ( query_skill("taoism", 1) >= improve * 10)
			improve = (int)query_skill("taoism", 1) / 10;
		if ( query_skill("ziyunyin", 1) >= improve * 10)
			improve = (int)query_skill("ziyunyin", 1) / 10;
		if ( query_skill("zhengqijue", 1) >= improve * 10)
			improve = (int)query_skill("zhengqijue", 1) / 10;
		if ( query_skill("poison", 1) >= improve * 10)
			improve = (int)query_skill("poison", 1) / 10;		
	}
	return (int)query("spi") + query_temp("apply/spirit") + improve;
}

// 福緣 -- 機緣好
int query_kar()
{
	return (int)query("kar") + query_temp("apply/karma");
}

// 容貌 -- 對定力低的異性有震懾力
int query_per()
{
	return (int)query("per") + query_temp("apply/personality");
}

// 定力 -- 出手破綻少，不易被反擊，對方進功成功率低
int query_cps()
{
	return (int)query("cps") + query_temp("apply/composure");
}

// 膽識 -- 出手成功率高
int query_cor()
{
	return (int)query("cor") + query_temp("apply/courage");
}

// 獸類馴服度 -- 
int query_obe()
{	
	return (int)query("obe") + query_temp("apply/obedience");
}

