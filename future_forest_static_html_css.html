<!doctype html>
<html lang="en">
<head>
  <meta charset="utf-8" />
  <meta name="viewport" content="width=device-width, initial-scale=1" />
  <title>Future Forest: Digital Echoes</title>
  <meta name="description" content="An evolving, participatory artwork where movement, music, and memory seed a living digital grove. By Amenda Tate." />
  <style>
    /* --------- Base / tokens --------- */
    :root {
      --bg: #ffffff;
      --ink: #0b1020;           /* near-black for strong contrast */
      --ink-dim: #334155;       /* slate-ish */
      --primary: #065f46;       /* emerald-700 */
      --primary-contrast: #ffffff;
      --surface: #f1f5f9;       /* slate-100 */
      --surface-2: #ecfdf5;     /* emerald-50 */
      --ring: #065f46;
      --max: 72rem;             /* 1152px */
      --radius: 1rem;           /* 16px */
    }

    html { font-size: 18px; }
    body {
      margin: 0;
      font-family: Futura, "Grantha Sangam MN", -apple-system, system-ui, Segoe UI, Roboto, Helvetica, Arial, sans-serif;
      line-height: 1.6;
      color: var(--ink);
      background: var(--bg);
      text-rendering: optimizeLegibility;
      -webkit-font-smoothing: antialiased;
    }
    a { color: var(--primary); text-decoration-thickness: 2px; text-underline-offset: 3px; }
    a:focus-visible, button:focus-visible, input:focus-visible, textarea:focus-visible { outline: 3px solid var(--ring); outline-offset: 2px; }

    .container { max-width: var(--max); padding: 0 1rem; margin: 0 auto; }
    .sr-only { position:absolute; width:1px; height:1px; padding:0; margin:-1px; overflow:hidden; clip:rect(0,0,0,0); white-space:nowrap; border:0; }

    /* --------- Header --------- */
    header { position: sticky; top: 0; background: rgba(255,255,255,0.95); backdrop-filter: blur(8px); border-bottom: 1px solid #e5e7eb; z-index: 10; }
    .nav { display: flex; align-items: center; justify-content: space-between; gap: 1rem; padding: .75rem 0; }
    .brand { display: flex; align-items: center; gap: .5rem; text-decoration: none; color: inherit; }
    .brand-title { font-weight: 800; letter-spacing: .05em; text-transform: uppercase; }
    /* Use Eurostile if provided */
    .brand-title, .hero-title {
      font-family: Eurostile, "Eurostile Next", Microgramma, -apple-system, system-ui, sans-serif;
    }
    nav ul { display: none; gap: 1rem; list-style: none; margin: 0; padding: 0; }
    @media (min-width: 768px) { nav ul { display: flex; } }

    .btn { display:inline-block; border:0; background: var(--primary); color: var(--primary-contrast); padding: .65rem 1rem; border-radius: 999px; font-weight: 700; cursor: pointer; }
    .btn.secondary { background: #0ea5e9; } /* cyan-500 for variety with good contrast */
    .btn:where(:hover,:focus-visible) { filter: brightness(.95); }

    /* --------- Hero --------- */
    .hero { position: relative; color: #fff; }
    .hero-media { position:absolute; inset:0; z-index:-1; }
    .hero-media::before { content:""; position:absolute; inset:0; background: linear-gradient(to bottom, rgba(0,0,0,.7), rgba(0,0,0,.2), rgba(0,0,0,.75)); }
    .hero .container { padding: 5rem 1rem 4rem; }
    .kicker { display:inline-flex; align-items:center; gap:.5rem; background: rgba(255,255,255,.95); color: var(--ink); border-radius: 999px; padding: .25rem .6rem; font-size: .9rem; }
    .hero-title { font-size: clamp(2rem, 5vw, 3.5rem); margin: .75rem 0 0; color:#fff; text-transform: uppercase; letter-spacing: .02em; text-shadow: 0 2px 6px rgba(0,0,0,.5); }
    .hero-sub { font-family: "Colonna MT", "Cinzel Decorative", serif; text-transform: uppercase; letter-spacing: .06em; font-size: clamp(1.5rem, 3.5vw, 2.2rem); margin:.25rem 0 0; color:#fff; text-shadow: 0 2px 6px rgba(0,0,0,.5); }
    .hero p { max-width: 40ch; font-size: 1.15rem; margin-top: 1rem; }
    .hero-actions { display:flex; gap:.75rem; flex-wrap: wrap; margin-top: 1rem; }
    .hero-video { width:100%; height:100%; object-fit: cover; opacity:.7; }

    /* --------- Sections --------- */
    section { padding: 3rem 0; }
    .section-title { font-size: 1.8rem; font-weight: 800; letter-spacing: .01em; display:flex; align-items:center; gap:.5rem; }
    .muted { color: var(--ink-dim); }
    .grid { display:grid; gap: 1rem; }
    @media (min-width: 768px) { .grid-2 { grid-template-columns: 1.2fr .8fr; } .grid-3 { grid-template-columns: repeat(3, 1fr);} .grid-4 { grid-template-columns: repeat(4, 1fr);} }
    .card { background: var(--surface); border: 1px solid #e5e7eb; border-radius: var(--radius); overflow: clip; }
    .card h3 { margin: 0; font-size: 1rem; }
    .card .body { padding: 1rem; font-size: .95rem; }
    .chip { display:inline-block; background: var(--surface-2); color: #064e3b; padding: .25rem .5rem; border-radius: 999px; font-size: .85rem; }

    .about-photo { width: 100%; height: auto; display: block; }

    /* Details/summary behave like accordion without JS */
    details { background: var(--surface); border: 1px solid #e5e7eb; border-radius: var(--radius); padding: .5rem .75rem; }
    details + details { margin-top: .5rem; }
    summary { cursor: pointer; font-weight: 700; }

    /* Visit map placeholder */
    .map { aspect-ratio: 16/10; display:flex; align-items:center; justify-content:center; background: linear-gradient(135deg, var(--surface), var(--surface-2)); border-radius: var(--radius); border:1px solid #e5e7eb; }

    /* Forms */
    label { display:block; font-weight:700; margin-top:.5rem; }
    input, textarea { width:100%; padding:.6rem .75rem; border-radius:.6rem; border:1px solid #cbd5e1; font: inherit; color: inherit; background:#fff; }
    textarea { min-height: 7rem; }
    .row { display:grid; gap:.75rem; }
    @media (min-width: 640px) { .row-2 { grid-template-columns: repeat(2, 1fr);} }

    /* Footer */
    footer { background: #fafafa; border-top: 1px solid #e5e7eb; }

    /* Utilities */
    .divider { height:1px; background: linear-gradient(to right, transparent, #e5e7eb, transparent); margin: 3rem 0; }
  </style>
</head>
<body>
  <a class="sr-only" href="#main">Skip to content</a>
  <header>
    <div class="container nav" role="navigation" aria-label="Primary">
      <a class="brand" href="#home">
        <img src="/Future-Forest-Icon.svg" alt="Future Forest logo" width="40" height="40" />
        <span class="brand-title">Future Forest</span>
      </a>
      <nav aria-label="Site">
        <ul>
          <li><a href="#about">About</a></li>
          <li><a href="#stations">Stations</a></li>
          <li><a href="#shrine">Shrine</a></li>
          <li><a href="#timeline">Timeline</a></li>
          <li><a href="#visit">Visit</a></li>
          <li><a href="#get-involved">Get Involved</a></li>
          <li><a href="#access">Accessibility</a></li>
        </ul>
      </nav>
      <a class="btn" href="#rsvp">RSVP</a>
    </div>
  </header>

  <main id="main">
    <!-- Hero -->
    <section id="home" class="hero" aria-label="Hero">
      <div class="hero-media" aria-hidden="true">
        <video class="hero-video" autoplay muted loop playsinline poster="https://images.unsplash.com/photo-1500530855697-b586d89ba3ee?q=80&w=2400&auto=format&fit=crop">
          <source src="" type="video/mp4" />
        </video>
      </div>
      <div class="container">
        <span class="kicker">Interactive art • community co‑creation • ecology of futures</span>
        <h1 class="hero-title">FUTURE FOREST</h1>
        <p class="hero-sub">DIGITAL ECHOES</p>
        <p>An evolving, participatory artwork where movement, music, and memory seed a living digital grove. Add your gestures, voices, and stories—watch the forest grow.</p>
        <div class="hero-actions">
          <a class="btn" href="#stations">Explore Stations</a>
          <a class="btn secondary" href="#trailer">Watch trailer</a>
        </div>
      </div>
    </section>

    <div class="divider" role="presentation"></div>

    <!-- About -->
    <section id="about" aria-labelledby="about-title">
      <div class="container grid grid-2">
        <div>
          <h2 id="about-title" class="section-title">About the Creator</h2>
          <p class="muted">Amenda Tate (she/her) — PhD student in Human‑Computer Interaction at Iowa State University; MFA in Integrated Visual Arts.</p>
          <p><strong>Amenda Tate</strong> is the creator of <em>FUTURE FOREST: DIGITAL ECHOES</em>, a participatory art project that blends movement, sound, and story. Her work integrates universal design and museum‑education heuristics to cultivate inclusive, multisensory experiences.
          As an artist‑researcher, Amenda explores how interactive systems can invite embodied inquiry and shared authorship, collaborating with community partners and accessibility advocates to align creative practice with care and belonging.</p>
          <p>
            <a class="btn" href="/Amenda-Tate-CV.pdf">Download CV (PDF)</a>
            <a class="btn secondary" href="/Amenda-Tate-Bio.pdf">Full Bio (PDF)</a>
          </p>
        </div>
        <div>
          <figure class="card">
            <img class="about-photo" src="/amenda-headshot.jpg" alt="Headshot of Amenda Tate" />
          </figure>
        </div>
      </div>
    </section>

    <div class="divider" role="presentation"></div>

    <!-- Stations -->
    <section id="stations" aria-labelledby="stations-title">
      <div class="container">
        <h2 id="stations-title" class="section-title">Interactive Stations</h2>
        <p class="muted">Four small portals + one collaborative projection gather movement, voice, and choices into a living grove.</p>
        <div class="grid grid-4" style="margin-top:1rem;">
          <article class="card"><div class="body"><h3>Portal I — Motion Grove</h3><p>Your gestures seed branches; slower movement grows thicker rings; quick motions spark new leaves. <span class="chip">Full body • seated options</span></p></div></article>
          <article class="card"><div class="body"><h3>Portal II — Chorus Canopy</h3><p>Hum or speak. Voices map to birdsong nodes; harmony unlocks rare fauna. <span class="chip">Mic input • quiet room cues</span></p></div></article>
          <article class="card"><div class="body"><h3>Portal III — Light Lichen</h3><p>Trace with a wand; light‑drawn paths become bioluminescent patterns. <span class="chip">Handheld wand • tactile overlay</span></p></div></article>
          <article class="card"><div class="body"><h3>Portal IV — Memory Seedbank</h3><p>Choose prompts; record a short reflection that becomes a seed packet in the forest. <span class="chip">Private mode • captions</span></p></div></article>
        </div>
        <article class="card" style="margin-top:1rem;">
          <div class="body"><h3>Collaborative Projection — “Canopy Synthesis”</h3><p>Inputs from all four portals synthesize into a large, gently reactive canopy. It visualizes community presence in real time, honoring quiet participation and celebrating collective rhythm.</p></div>
        </article>
      </div>
    </section>

    <div class="divider" role="presentation"></div>

    <!-- Shrine -->
    <section id="shrine" aria-labelledby="shrine-title">
      <div class="container grid grid-2">
        <div>
          <h2 id="shrine-title" class="section-title">Translucent Shrine of Eternal Blooms</h2>
          <p>A contemplative alcove where unique specimens are encased in paraffin—a meditation on care, preservation, and future archaeology. A tactile diagram and audio description accompany the display. Quiet seating welcomes slow looking.</p>
          <details>
            <summary>Lifecycle Flow (from petroleum to preservation)</summary>
            <ol>
              <li>Geologic time forms petroleum from ancient organic matter.</li>
              <li>Extraction & refining yield paraffin wax.</li>
              <li>Wax encasement slows decay, invites reflection on stewardship.</li>
              <li>Ritual display frames care practices for future archaeologies.</li>
            </ol>
          </details>
          <details>
            <summary>Care & Handling</summary>
            <ul>
              <li>Low‑heat environment; no direct sunlight.</li>
              <li>Fragrance‑free gallery policy for sensory safety.</li>
              <li>Tactile replica available; original remains protected.</li>
            </ul>
          </details>
        </div>
        <figure class="card">
          <img src="https://images.unsplash.com/photo-1520697222860-8504e3be0f57?q=80&w=1600&auto=format&fit=crop" alt="Translucent wax‑encased botanical specimen lit from behind" style="width:100%; height:auto; display:block;" />
        </figure>
      </div>
    </section>

    <div class="divider" role="presentation"></div>

    <!-- Timeline -->
    <section id="timeline" aria-labelledby="timeline-title">
      <div class="container">
        <h2 id="timeline-title" class="section-title">Timeline</h2>
        <div class="grid grid-3" style="margin-top:1rem;">
          <article class="card"><div class="body"><h3>Opening Iteration</h3><p class="muted"><strong>Nov 8, 2025</strong></p><p>First public showing with guided micro‑activations and live documentation.</p><p><a class="btn" href="#rsvp">RSVP</a></p></div></article>
          <article class="card"><div class="body"><h3>Community Making Day</h3><p class="muted"><strong>Nov 15, 2025</strong></p><p>Drop‑in participatory workshops; contribute artifacts to the shrine replicas.</p><p><a class="btn" href="#visit">Details</a></p></div></article>
          <article class="card"><div class="body"><h3>VIP Sneak Peek</h3><p class="muted"><strong>Dec 1, 2025</strong></p><p>Ticketed evening with artist talk, soundscape demo, and behind‑the‑scenes tech tour.</p><p><a class="btn" href="#rsvp">RSVP</a></p></div></article>
        </div>
      </div>
    </section>

    <div class="divider" role="presentation"></div>

    <!-- Visit -->
    <section id="visit" aria-labelledby="visit-title">
      <div class="container grid grid-2">
        <div>
          <h2 id="visit-title" class="section-title">Visit</h2>
          <p>Mainframe Studios • 900 Keo Way, Des Moines, IA • Gallery Hours vary by event.</p>
          <ul>
            <li>Wayfinding: large‑print signage; elevator access; seating throughout.</li>
            <li>Sound: quiet hours posted; headphones available upon request.</li>
            <li>Sensory: low‑scent policy; dimmable lighting; tactile guides.</li>
          </ul>
          <p>
            <a class="btn" href="#rsvp">Reserve Free Ticket</a>
            <a class="btn secondary" href="#get-involved">Support the Project</a>
          </p>
        </div>
        <div class="card"><div class="body">
          <h3>Map & Parking</h3>
          <div class="map" aria-label="Map placeholder"><span aria-hidden="true">📍</span></div>
          <p>Accessible parking and drop‑off available at main entrance. Ramps and elevators serve all public areas.</p>
        </div></div>
      </div>
    </section>

    <div class="divider" role="presentation"></div>

    <!-- Get Involved -->
    <section id="get-involved" aria-labelledby="involved-title">
      <div class="container">
        <h2 id="involved-title" class="section-title">Get Involved</h2>
        <div class="grid grid-3" style="margin-top:1rem;">
          <article class="card"><div class="body"><h3>Volunteer</h3><p>Help welcome visitors, facilitate stations, and document stories. Training provided; flexible shifts.</p><p><a class="btn" href="#">Sign Up</a></p></div></article>
          <article class="card"><div class="body"><h3>Contribute</h3><p>Support tech, accessibility tools, and community workshops. All gifts make an impact.</p><p><a class="btn" href="#">Donate</a></p></div></article>
          <article class="card"><div class="body"><h3>Collaborate</h3><p>Educators, care partners, artists—let’s co‑design activations that meet your community’s needs.</p><p><a class="btn" href="#">Propose an Idea</a></p></div></article>
        </div>

        <div class="grid grid-2" style="margin-top:1rem;">
          <form class="card" onsubmit="event.preventDefault(); alert('Thanks! This demo form does not submit yet.');" aria-labelledby="contact-title">
            <div class="body">
              <h3 id="contact-title">Contact</h3>
              <div class="row row-2">
                <div><label for="name">Your name</label><input id="name" name="name" autocomplete="name" /></div>
                <div><label for="email">Email</label><input id="email" name="email" type="email" autocomplete="email" /></div>
              </div>
              <div>
                <label for="message">Message</label>
                <textarea id="message" name="message" placeholder="How would you like to be involved?"></textarea>
              </div>
              <button class="btn" type="submit">Send</button>
            </div>
          </form>
          <div class="card"><div class="body">
            <h3>Press Kit</h3>
            <ul>
              <li>Project trailer (link)</li>
              <li>Image stills (zip)</li>
              <li>Artist statement & specs (pdf)</li>
            </ul>
            <p><a href="#">Instagram</a> · <a href="#">GitHub</a></p>
          </div></div>
        </div>
      </div>
    </section>

    <div class="divider" role="presentation"></div>

    <!-- Accessibility -->
    <section id="access" aria-labelledby="access-title">
      <div class="container">
        <h2 id="access-title" class="section-title">Accessibility & Inclusion</h2>
        <div class="grid grid-3" style="margin-top:1rem;">
          <article class="card"><div class="body"><h3>Communication</h3><p>Large‑print labels; audio description; captioned media; clear wayfinding. Staff trained in multiple participation modes.</p></div></article>
          <article class="card"><div class="body"><h3>Sensory Considerations</h3><p>Quiet hours; optional ear covers; low‑scent policy; adjustable lighting; seating for rest.</p></div></article>
          <article class="card"><div class="body"><h3>Mobility & Input</h3><p>Seated/standing options; alternative input devices; no time traps; paths ≥ 36"; assistance on request.</p></div></article>
        </div>
        <p class="muted" style="margin-top:1rem;">Designed with reference to ADA Title II/III and WCAG 2.2 AA guidelines; onsite adjustments made in collaboration with visitors.</p>
      </div>
    </section>

    <div class="divider" role="presentation"></div>

    <!-- RSVP -->
    <section id="rsvp" aria-labelledby="rsvp-title">
      <div class="container">
        <div class="card"><div class="body">
          <h2 id="rsvp-title" class="section-title">Reserve your spot</h2>
          <form onsubmit="event.preventDefault(); alert('Thanks! This demo RSVP does not submit yet.');">
            <div class="row row-2">
              <div><label for="rsvp-name">Name</label><input id="rsvp-name" name="name" autocomplete="name" /></div>
              <div><label for="rsvp-email">Email</label><input id="rsvp-email" name="email" type="email" autocomplete="email" /></div>
            </div>
            <div class="row row-2">
              <div><label for="rsvp-date">Preferred date (e.g., Nov 8)</label><input id="rsvp-date" name="date" /></div>
              <div><label for="rsvp-guests"># of guests</label><input id="rsvp-guests" name="guests" inputmode="numeric" pattern="[0-9]*" /></div>
            </div>
            <p class="muted">Free; donations welcome to expand accessibility resources.</p>
            <button class="btn" type="submit">RSVP</button>
          </form>
        </div></div>
      </div>
    </section>
  </main>

  <footer>
    <div class="container" style="padding:2rem 1rem;">
      <div class="grid grid-3">
        <div>
          <strong>Future Forest</strong>
          <p class="muted">An inclusive, participatory exploration of care and co‑creation. © <span id="year"></span>.</p>
        </div>
        <div>
          <strong>Links</strong>
          <ul>
            <li><a href="#about">About</a></li>
            <li><a href="#stations">Stations</a></li>
            <li><a href="#shrine">Shrine</a></li>
            <li><a href="#timeline">Timeline</a></li>
            <li><a href="#visit">Visit</a></li>
          </ul>
        </div>
        <div>
          <strong>Newsletter</strong>
          <form onsubmit="event.preventDefault(); alert('Thanks! This demo newsletter form does not submit yet.');">
            <label for="news-email" class="sr-only">Email</label>
            <input id="news-email" type="email" placeholder="you@example.com" autocomplete="email" />
            <button class="btn" type="submit" style="margin-top:.5rem;">Join</button>
          </form>
        </div>
      </div>
    </div>
  </footer>

  <script>
    // Lightweight progressive enhancements
    document.getElementById('year').textContent = new Date().getFullYear();
    // Respect reduced motion users (no additional JS animations used here)
  </script>
</body>
</html>
