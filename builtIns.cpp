const Una e1 = Una( { 1., 0., 0., 0., 0. } );
const Una e2 = Una( { 0., 1., 0., 0., 0. } );
const Una em = Una( { 0., 0., 1., 0., 0. } );
const Una ep = Una( { 0., 0., 0., 1., 0. } );
const Una et = Una( { 0., 0., 0., 0., 1. } );

const Una e0 = Una( { 0., 0., 1., 1., 1. } );
const Una eo = Una( { 0., 0.,-1., 1., 0. } );

const Bi e12 = e1 ^ e2;
const Bi e10 = e1 ^ e0;
const Bi e20 = e2 ^ e0;
const Tri e120 = e12 ^ e0; //hello big bang

const Bi emp = em ^ ep; //origin in some sense

const Bi e1p = e1 ^ ep;
const Bi e2p = e2 ^ ep;
const Tri e12p = e12 ^ ep;

const Bi e1m = e1 ^ em;
const Bi e2m = e2 ^ em;
const Tri e12m = e12 ^ em;

// boosts
const Bi e1t = e1 ^ et;
const Bi e2t = e2 ^ et;
const Tri e12t = e12 ^ et; // 1D CGA / celestial pss

// time translations
const Bi ept = ep ^ et;
const Bi emt = em ^ et;
const Bi e0t = e0 ^ et;

// point reflections
const Tri e2mp = e2m ^ ep;
const Tri e1mp = e1m ^ ep;
const Tri e1mt = e1m ^ et;
const Tri e2mt = e2m ^ et;
const Tri e1pt = e1p ^ et;
const Tri e2pt = e2p ^ et;

//pss's for deSitter etc
const Quad e120t = e120 ^ et;
const Quad e12pt = e12p ^ et;
const Quad e12mt = e12m ^ et;

const Pent e12mpt = e12m ^ ept;