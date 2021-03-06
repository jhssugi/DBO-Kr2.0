CNtlTSTrigger
{
	sm = 1;
	sq = 1;
	qc = -1;
	rq = 0;
	tid = 2955;
	title = 295502;

	CNtlTSGroup
	{
		gid = 0;

		CDboTSContEnd
		{
			cid = 254;
			prelnk = "101;";
			type = 1;
		}
		CDboTSContEnd
		{
			cid = 253;
			prelnk = "1;0;252;";
			type = 0;
		}
		CDboTSContStart
		{
			cid = 0;
			stdiag = 295507;
			nolnk = 253;
			rm = 0;
			yeslnk = 1;

			CDboTSCheckLvl
			{
				maxlvl = 100;
				minlvl = 56;
			}
			CDboTSClickNPC
			{
				npcidx = "4894101;";
			}
			CDboTSCheckClrQst
			{
				and = "2954;";
				flink = 0;
				flinknextqid = "2956;";
				not = 0;
			}
		}
		CDboTSContGAct
		{
			cid = 101;
			elnk = 255;
			nextlnk = 254;
			prelnk = "100;";

			CDboTSActSToCEvt
			{
				apptype = 0;
				cnt1 = 0;
				eitype = 0;
				idx0 = -1;
				cnt0 = 0;
				cnt2 = 0;
				ectype = -1;
				etype = 1;
				idx1 = -1;
				taid = 1;
				esctype = 0;
				idx2 = -1;
			}
		}
		CDboTSContGCond
		{
			cid = 3;
			prelnk = "2;";
			nolnk = 255;
			rm = 0;
			yeslnk = 100;

			CDboTSCheckSToCEvt
			{
				itype = 0;
			}
		}
		CDboTSContReward
		{
			canclnk = 255;
			cid = 100;
			rwdzeny = 0;
			desc = 295514;
			nextlnk = 101;
			rwdexp = 0;
			rwdtbl = 295501;
			rwdtype = 0;
			ltime = -1;
			prelnk = "3;";
			usetbl = 1;

			CDboTSClickNPC
			{
				npcidx = "4894101;";
			}
		}
		CDboTSContGAct
		{
			cid = 252;
			elnk = 255;
			nextlnk = 253;
			prelnk = "2;";
		}
		CDboTSContProposal
		{
			cancellnk = 253;
			cid = 1;
			cont = 295508;
			gtype = 2;
			oklnk = 2;
			area = 295501;
			goal = 295504;
			sort = 295505;
			prelnk = "0;";
			ds = 1;
			grade = 0;
			rwd = 100;
			title = 295502;
		}
		CDboTSContGAct
		{
			cid = 2;
			elnk = 252;
			nextlnk = 3;
			prelnk = "1;";

			CDboTSActNPCConv
			{
				conv = 295509;
				ctype = 1;
				idx = 4894101;
				taid = 2;
			}
			CDboTSActSToCEvt
			{
				apptype = 0;
				cnt1 = 3;
				eitype = 0;
				idx0 = 13213200;
				cnt0 = 12;
				cnt2 = 0;
				ectype = -1;
				etype = 0;
				idx1 = 18152100;
				taid = 3;
				esctype = 0;
				idx2 = -1;
			}
			CDboTSActRegQInfo
			{
				cont = 295508;
				m1fx = "2925.870117";
				m1fy = "0.000000";
				sort = 295505;
				m0fy = "0.000000";
				m0pat = 2;
				m1fz = "-4238.439941";
				grade = 132203;
				m0fx = "2897.159912";
				m0ttip = 295515;
				m1pat = 2;
				m1widx = 1;
				rwd = 100;
				taid = 1;
				title = 295502;
				gtype = 2;
				area = 295501;
				goal = 295504;
				m0fz = "-4207.959961";
				m0widx = 1;
				m1ttip = 295516;
				scitem = -1;
				stype = 2;
			}
		}
	}
}

