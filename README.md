MakAir — Covid-19 Ventilator
=====


**Mass-producible open-source Covid-19 ARDS ventilator. Aims at helping hospitals cope with a possible shortage of professional ventilators during the outbreak. Worldwide.**

We are a distributed team of [200+ contributors](http://makersforlife.fr/) (engineering, medical, regulatory, etc.), mostly spread through France. Makers, developers, university teachers, researchers and medical teams collaborated on this project. Our testing & assembly operations are located in France.

As to ensure international outreach, we made sure that contents required to build your own MakAir ventilator are available in English. The MakAir project has [a website of its own](https://makair.life/).

If you're new there, please read the explanations below. _Your contributions are much welcome!_

![MakAir Logo](./res/assets/logo-readme.png)

---

**Quick introduction video:**

<p align="center">
  <a href="https://www.youtube.com/watch?v=6LeZjULZnUc">
    <img alt="Play Introduction Video" src="./res/assets/play-introduction.jpg" height="320">
  </a>
</p>

---

# Abstract

Roughly, the idea is as follows: as of April 2020 and due to the Covid-19 pandemic, hospitals throughout the world may start lacking mechanical artificial ventilators. We built a pump, and a valve system (controlled by electronics). This way, the breathing cycle can be enforced by proper air routing through the valve system.

Our ventilator is able to handle pressure-controlled breathing, stabilized using a [PID controller](https://en.wikipedia.org/wiki/PID_controller) in the software.

In order to ensure a proper breathing cycle (inhale + exhale), multiple valves need to be connected together to form a circuit. The motors needs to be controlled in harmony so that the air routing between each valve unit is consistent.

This project provides all the parts required to build a good-enough [ARDS](https://en.wikipedia.org/wiki/Acute_respiratory_distress_syndrome) ventilator from mass-produced components. We provide all the required mechanical parts, electronics designs & boards, and firmwares. This ventilator can be 3D-printed and ran on an Arduino board (the maker way), though we **highly advise** that you work with industrial processes as to mold medical-grade plastic parts and assemble the whole ventilator (this would be required for the built ventilator to pass all medical certifications).

We target a per-unit cost well under 500 EUR, which could easily be shrunk down to 200 EUR or even 100 EUR per ventilator given proper economies of scale, as well as choices of cheaper on-the-shelf components (eg. servomotors).

Mechanically-speaking, the overall system is composed of sub-components that can be plugged together and wired to form an air circuit, namely:

- **Air pump** (called "Blower");
- **Air pump casing fit** (called "Blower Holder");
- **Valve system** (called "Pressure Valve");
- **Oxygen Mixer valve** (called "Oxygen Mixer");
- **Air filter casing (patient variant)** (called "Patient Filter Box");
- **Air filter casing (machine variant)** (called "Machine Filter Box"; intake + outtake);
- **Connectors** (called "Pneumatic Connectors");
- **Fan support** (called "Fan Holder");

All those components are fitted in box (ie. a container) that we designed:

- **Housing container** (called "Container");

![MakAir Container + UI](./res/assets/abstract-readme.jpg)

# ⚠️ Warning Notices

**A few important words before you start:**

1. Though 3D-printing (FDM and SLA) can be used to build your own ventilator — this will definitely not scale well to mass-produce MakAir ventilators, and parts might be brittle or leak air. Please work with proper industrial methods and processes if you want to build your own MakAir ventilators.

2. As ARDS patients are sedated, their breathing cycle is forced by mechanical ventilation, while they are intubated. A failing ventilator (due to bad mechanics, pneumatics or software) could kill the patient (O2 desaturation), or permanently damage their lung alveoli (overpressure). It is critical that any self-built MakAir ventilator is tested against a lung simulator system (eg. [ASL 5000](https://www.ingmarmed.com/product/asl-5000-breathing-simulator/)), and validated by medical experts.

3. Medical-grade plastic should be used to produce ventilators, and any kind of grease or adhesive chemicals must be avoided in the ventilator. The ventilators should be produced in a [cleanroom](https://en.wikipedia.org/wiki/Cleanroom) as to avoid dust & germ contaminations.

4. The pneumatic circuit should be thoroughly tested for leaks and its ability to withstand elevated positive air pressure. Joints should be used where relevant, and medical-grade flexible pipes should be used between components.

5. While the MakAir ventilators produced on-site in France were validated by a medical & engineering board, you should independantly seek validation of the MakAir ventilators that you produce; as your assembly methods or parts may vary with ours.

_MakAir and Makers For Life should not be held resposible — at any time, for harm caused to human life (eg. lung damage or loss of life). By building your own MakAir, you are held responsible for its safety validations & use._

# How To Build?

This section aims at introducing you on how to manufacture your own MakAir — _the 3D-printed way_. In other words, we will explain there how to build a DIY MakAir using on-the-shelf parts and 3D printers.

## 1️⃣ Print all the parts

In order to 3D-print your MakAir, please first ensure you have access to a [SLS](https://en.wikipedia.org/wiki/Selective_laser_sintering) 3D printer at best (eg. [HP Multi Jet Fusion](https://www8.hp.com/us/en/printers/3d-printers/products/multi-jet-technology.html)), or otherwise a [SLA](https://en.wikipedia.org/wiki/Stereolithography) printer (eg. [Formlabs Form 3](https://formlabs.com/3d-printers/form-3/)). If you want to use a [FDM](https://en.wikipedia.org/wiki/Fused_filament_fabrication) printer (eg. [MakerBot Method](https://www.makerbot.com/3d-printers/method/)), please note that some precise parts have been optimized for SLA or SLS printing. Some parts may not print well using FDM printers, even on decent hardware.

**👉 To sum up:** at best, use a SLS metal printer, else, use a SLA resin printer. If you do not have access to either of these, you may fallback on a FDM filament printer (using [PLA](https://en.wikipedia.org/wiki/Polylactic_acid) or [ABS](https://en.wikipedia.org/wiki/Acrylonitrile_butadiene_styrene) filaments).

### 1. Parts

You can find a list of all parts that should be 3D-printed, as well as the number of parts that should be printed for each one (pick the last active version for each part):

- 1 x **Blower** — Print [all STL parts](./src/mechanics/parts/blower/printing/stl) using the same printer (SLA or SLS; FDM discouraged; 50 microns minimum);
- 2 x **Pressure Valve** — Print [all STL parts](./src/mechanics/parts/pressure-valve/printing/stl) using the same printer (SLA, SLS or FDM; 200 microns minimum);
- 1 x **Oxygen Mixer** — Print [the STL part](./src/mechanics/parts/oxygen-mixer/printing/stl) (SLA or SLS; FDM discouraged; 100 microns minimum);
- 1 x **Patient Filter Box** — Print [all STL parts](./src/mechanics/parts/patient-filter-box/printing/stl) using the same printer (SLA, SLS or FDM; 100 microns minimum);
- 1 x **Machine Filter Box (Intake)** — Print [all STL parts](./src/mechanics/parts/machine-filter-box/printing/stl) using the same printer, make sure that you pick the proper sub-part (SLA or SLS; FDM discouraged; 100 microns minimum);
- 1 x **Machine Filter Box (Outtake)** — Print [all STL parts](./src/mechanics/parts/machine-filter-box/printing/stl) using the same printer, make sure that you pick the proper sub-part (SLA or SLS; FDM discouraged; 100 microns minimum);
- 1 x **Pneumatic Connectors (Blower)** — Print [the STL part](./src/mechanics/parts/pneumatic-connectors/printing/stl) using the same printer, make sure that you pick the proper sub-part (SLA or SLS; FDM discouraged; 100 microns minimum);
- 1 x **Pneumatic Connectors (O2)** — Print [the STL part](./src/mechanics/parts/pneumatic-connectors/printing/stl) using the same printer, make sure that you pick the proper sub-part (SLA or SLS; FDM discouraged; 100 microns minimum);
- 1 x **Pneumatic Connectors (No Pressure)** — Print [the STL part](./src/mechanics/parts/pneumatic-connectors/printing/stl) using the same printer, make sure that you pick the proper sub-part (SLA or SLS; FDM discouraged; 100 microns minimum);
- 1 x **Pneumatic Connectors (Pressure)** — Print [the STL part](./src/mechanics/parts/pneumatic-connectors/printing/stl) using the same printer, make sure that you pick the proper sub-part (SLA or SLS; FDM discouraged; 100 microns minimum);

If you are using your own proprietary blower — _in addition to the parts above_ — please adjust the [Blower Holder](./src/mechanics/parts/blower-holder) CAD model and print it as well (this one prints well using a FDM printer at worst).

### 2. Container

Now that you got all parts printed, you may assemble them in the MakAir container box. We recommend that you build the container using laser-cut acrylic panels. You may find the container CAD model for [Fusion 360](./src/mechanics/container/molding/fusion) or as a [STEP file](./src/mechanics/container/molding/step).

_Please ensure that you cut your acrylic panels using the same sizes than stated on our models; as those sizes are optimized to contain all required parts and electronics in the minimum amount of space._

## 2️⃣ Setup the electronics

Electronics are comprised of two parts: the firmware controller board (typically, an Arduino), and the "raw" PCB electronics (LCD, interface buttons, alarm beeper, etc.). Those parts make up the motherboard, on the top of which a rigid panel is mounted, and user instructions are printed (eg. control button bindings).

### 1. Motherboard

The motherboard electronic schematics and wiring diagrams [can be found there](./src/electronics/motherboard/schematics). Please pick the last version available.

👋 _If you need help on this step, you may [open an issue](https://github.com/makers-for-life/makair/issues/new)._

### 2. Control Unit Screen

The control unit is made of a [Raspberry Pi 4](https://www.raspberrypi.org/products/raspberry-pi-4-model-b/) computer, plugged to a [Raspberry Pi Touch Display](https://www.raspberrypi.org/products/raspberry-pi-touch-display/).

👋 _If you need help on this step, you may [open an issue](https://github.com/makers-for-life/makair/issues/new)._

## 3️⃣ Flash the firmware

### 1. Ventilator Firmware

Now that both mechanical parts and electronics are ready, you may flash the latest MakAir firmware binary on your firmware controller board (Arduino, ST Nucleo, or other).

Firmware release binaries are available for download on our [releases page](https://github.com/makers-for-life/makair/releases).

👋 _If you need help on this step, you may [open an issue](https://github.com/makers-for-life/makair/issues/new)._

### 2. Control Unit Runtime

The Control Unit should be built and ran on the Raspberry Pi 4 using instructions available on the [Control Unit](./src/software/control) documentation.

👋 _If you need help on this step, you may [open an issue](https://github.com/makers-for-life/makair/issues/new)._

# Components

## Mechanics

| Part | Version | Last Changelog | Ready? | Live CAD Models | Contributors |
| ---- | ------- | -------------- | ------ | --------------- | ------------ |
| [Blower](./src/mechanics/parts/blower) | V14 | Smaller form factor & more powerful | ✅ | [view model](https://a360.co/2JIBr8d) | Gabriel Moneyron + [Baptiste Jamin](https://github.com/baptistejamin) + [Valerian Saliou](https://github.com/valeriansaliou)
| [Blower Holder](./src/mechanics/parts/blower-holder) | V3 | Differentiate Model A and Model B | ✅ | [view a model](https://a360.co/2xiu2tr), [view b model](https://a360.co/2ViA05J) | Gabriel Moneyron + [Valerian Saliou](https://github.com/valeriansaliou)
| [Pressure Valve](./src/mechanics/parts/pressure-valve) | V6 | General improvements | ✅ | [view model](https://a360.co/2RyQLsr) | [Clement Niclot](https://github.com/clementniclot)
| [Oxygen Mixer](./src/mechanics/parts/oxygen-mixer) | V4 | Updated with correct O2 ID diameter, reinforced O2 nipple. | ✅ | [view model](https://a360.co/2XrUdIV) | [Yohann Nédélec](https://github.com/Melkaz) + Steven Daix
| [Patient Filter Box](./src/mechanics/parts/patient-filter-box) | V6 | Update input/output mensurations | ✅ | [view model](https://a360.co/2UT72dP) | Martial Medjber + [Eliott Vincent](https://github.com/eliottvincent)
| [Machine Filter Box (Intake)](./src/mechanics/parts/machine-filter-box) | V2 | Modeling corrections | ✅ | [view model](https://a360.co/2x1mhIx) | [Valerian Saliou](https://github.com/valeriansaliou)
| [Machine Filter Box (Outtake)](./src/mechanics/parts/machine-filter-box) | V2 | Modeling corrections | ✅ | [view model](https://a360.co/2XeSVAP) | [Valerian Saliou](https://github.com/valeriansaliou)
| [Pneumatic Connectors](./src/mechanics/parts/pneumatic-connectors) | V4 | Wall-mountable patient connectors | ✅ | [view o2 model](https://a360.co/3bVsX9N), [view blower model](https://a360.co/2UNMVgY), [view respiratory pressure model](https://a360.co/3av64c0), [view respiratory no pressure model](https://a360.co/2XZB5T0) | Gabriel Moneyron
| [Fan Holder](./src/mechanics/parts/fan-holder) | V2 | Wall-mounted version | ✅ | [view floor-mounted model](https://a360.co/2V8enEU), [view wall-mounted model](https://a360.co/3cLgsy1) | [Eliott Vincent](https://github.com/eliottvincent)
| [Container](./src/mechanics/container) | V2 | Update mensurations | ✅ | [view model](https://a360.co/2RlnfGp) | Arthur Dagard

## Electronics

| Board | Version | Major Changes | Ready? | Schematics | Contributors |
| ----- | ------- | ------------- | ------ | ---------- | ------------ |
| [Motherboard](./src/electronics/motherboard) | V2 | Working PCB w/ software | ✅ | [view schematic](./src/electronics/motherboard/schematics/V2/Electrical%20Schematics.pdf) | Vincent Le Cunff + Cherine Kamel + [Pierre Papin](https://github.com/pi-r-p)

## Software

[![Firmware Lint](https://github.com/makers-for-life/makair/workflows/Firmware%20Lint/badge.svg)](https://github.com/makers-for-life/makair/actions?query=workflow%3A%22Firmware+Lint%22) [![Firmware Unit Tests](https://github.com/makers-for-life/makair/workflows/Firmware%20Unit%20Tests/badge.svg)](https://github.com/makers-for-life/makair/actions?query=workflow%3A%22Firmware+Unit+Tests%22) [![Control Lint](https://github.com/makers-for-life/makair/workflows/Control%20Lint/badge.svg)](https://github.com/makers-for-life/makair/actions?query=workflow%3A%22Control+Lint%22) [![Telemetry All](https://github.com/makers-for-life/makair/workflows/Telemetry%20All/badge.svg)](https://github.com/makers-for-life/makair/actions?query=workflow%3A%22Telemetry+All%22)

| Runtime | Version | Major Changes | Ready? | Contributors |
| ------- | ------- | ------------- | ------ | ------------ |
| [Ventilator Firmware](./src/software/firmware) | V1.5.x | Initial test working | ✅ | [Emmanuel Feller](https://github.com/Mefl) + [Gautier de Saint Martin Lacaze](https://github.com/jabby) + [David Sferruzza](https://github.com/dsferruzza) + [Baptiste Jamin](https://github.com/baptistejamin) + [Gabriel Moneyron](https://github.com/Benhalor)
| [Control Unit](./src/software/control) | V1.1.x | Operational initial release | ✅ | [Valerian Saliou](https://github.com/valeriansaliou) + [Quentin Adam](https://github.com/waxzce) + [Arnaud Lefebvre](https://github.com/BlackYoup)
| [Telemetry Library](./src/software/telemetry) | V1.0.0 | Working serial parsing from firmware | ✅ | [David Sferruzza](https://github.com/dsferruzza)

# Schemes

## Pneumatic Circuit Scheme

[![Pneumatic Circuit Scheme](./docs/Pneumatics/Pneumatic%20Circuit/Pneumatic%20Circuit.png)](./docs/Pneumatics/Pneumatic%20Circuit/Pneumatic%20Circuit.png)

_(design by [Valerian Saliou](https://github.com/valeriansaliou))_

## Container Layout

### Top Part: Electronics (Power & Controllers)

[![Container Layout Electronics Drawing](./docs/Container/Container%20Layout/Container%20Layout%20Electronics.jpg)](./docs/Container/Container%20Layout/Container%20Layout%20Electronics.jpg)

_(design by Arthur Dagard; drawing by [Valerian Saliou](https://github.com/valeriansaliou))_

### Bottom Part: Pneumatics

[![Container Layout Pneumatics Drawing](./docs/Container/Container%20Layout/Container%20Layout%20Pneumatics.jpg)](./docs/Container/Container%20Layout/Container%20Layout%20Pneumatics.jpg)

_(design by Arthur Dagard; drawing by [Valerian Saliou](https://github.com/valeriansaliou))_

# News & Contact

## Updates

* Live updates on Telegram: [join "Newsroom MakAir (Covid-19 Ventilator)"](https://t.me/joinchat/AAAAAE_99-k7pKZur-GXCQ)
* YouTube channel: [view "MakAir" on YouTube](https://www.youtube.com/channel/UCcf_3KXjeJSMz39J6gsyTSg)
* Coordination on Slack: [request to join "Makers For Life"](https://github.com/makers-for-life/makair/issues/new) (open an issue)

## Contacts

* Open-source & questions: [please open an issue on GitHub](https://github.com/makers-for-life/makair/issues/new)
* Press contacts: [Grégory Thibord](https://twitter.com/thibord) ([email](mailto:gregory.thibord@lepalace.work))
* Medical contacts: [Pierre Antoine Gourraud](http://www.itun.nantes.inserm.fr/Team-5/Pierre-Antoine-Gourraud) ([email](mailto:pierre-antoine.gourraud@univ-nantes.fr))
* Industry relations: [Quentin Adam](http://waxzce.org/) ([email](mailto:quentin.adam@clever-cloud.com))
* Engineering contact (mechanics): [Valerian Saliou](https://valeriansaliou.name/) ([email](mailto:valerian@valeriansaliou.name))
* Engineering contact (software): [David Sferruzza](https://david.sferruzza.fr/) ([email](mailto:david.sferruzza@gmail.com))
* Engineering contact (electronics): Vincent Le Cunff ([email](mailto:v.lecunf@gmail.com))

# Sponsors & Contributors

This project would not have been possible without the support of those companies and organizations, which have put human, real estate and/or financial resources at work on the project:

* [Clever Cloud](https://www.clever-cloud.com/) (founding team)
* [Crisp](https://crisp.chat/) (founding team)
* [Cooprint](https://cooprint.fr/) (CAD)
* [SenX](https://senx.io/) (electronics)
* [Tronico](https://www.tronico-alcen.com/) (PCB design)
* [Renault Group](https://www.renault.fr/) (manufacturing)
* [SEB Group](https://www.groupeseb.com/) (manufacturing)
* [Le Palace Nantes](https://lepalace.work/) (team offices)
* [Parrot](https://www.parrot.com/) (hardware provider)
* [STMicroelectronics](https://www.st.com/) (hardware provider)
* [Diabeloop](https://www.diabeloop.com/) (regulatory help)
* [Legrand](https://www.legrand.fr/) (hardware provider)
* [RTsys](https://rtsys.eu/) (engineering provider)

We are supported by public entities as well, namely:

* [Defence Innovation Agency](https://www.defense.gouv.fr/) (Ministry of Armed Forces of France)
* [CEA](http://www.cea.fr/) (France)
* [CHU of Nantes](https://www.chu-nantes.fr/) (France)
* [University of Nantes](https://www.univ-nantes.fr/) (France)
* [City of Nantes](https://metropole.nantes.fr/) (France)
* [Region of Auvergne-Rhône-Alpes](https://www.auvergnerhonealpes.fr/) (France)

Adding to that, 200+ individual members of the project who contributed to technical, legal, medical and press subjects (and more).

# Press Coverage

## 📺 TV

* [France 3, 21st April 2020](https://www.youtube.com/watch?v=M3QLCvUyIII) (French-speaking)
* [TF1, 26th April 2020](https://www.youtube.com/watch?v=2X157RLbRIA) (French-speaking)

# Renders

## Mechanics

### The "Pressure Valve"

<p>
  <img alt="Pressure Valve Render" src="./src/mechanics/parts/pressure-valve/printing/schemes/V6/Pressure%20Valve%20(Render%201).png" height="240">
  <img alt="Pressure Valve Print" src="./src/mechanics/parts/pressure-valve/printing/schemes/V6/Pressure%20Valve%20(Print%201).jpg" height="240">
</p>

### The "Blower"

🎦 View: [Animation of the "Blower"](./src/mechanics/parts/blower/printing/schemes/V14/Blower%20(Animation%201).mp4)

<p>
  <img alt="Blower Render" src="./src/mechanics/parts/blower/printing/schemes/V14/Blower%20(Render%201).png" height="240">
  <img alt="Blower Render" src="./src/mechanics/parts/blower/printing/schemes/V14/Blower%20(Render%202).png" height="240">
  <img alt="Blower Render" src="./src/mechanics/parts/blower/printing/schemes/V14/Blower%20(Print%201).jpg" height="240">
  <img alt="Blower Render" src="./src/mechanics/parts/blower/printing/schemes/V14/Blower%20(Print%202).jpg" height="240">
</p>

### The "Blower Holder"

<p>
  <img alt="Blower Holder Model A Render" src="./src/mechanics/parts/blower-holder/printing/schemes/V3/Blower%20Holder%20V3%20(Model%20A)/Blower%20Holder%20Model%20A%20(Render%201).png" height="240">
  <img alt="Blower Holder Model B Render" src="./src/mechanics/parts/blower-holder/printing/schemes/V3/Blower%20Holder%20V3%20(Model%20B)/Blower%20Holder%20Model%20B%20(Render%201).png" height="240">
  <img alt="Blower Holder Print" src="./src/mechanics/parts/blower-holder/printing/schemes/Archives/V1/Blower%20Holder%20(Print%201).jpg" height="240">
</p>

### The "Oxygen Mixer"

<p>
  <img alt="Oxygen Mixer Render" src="./src/mechanics/parts/oxygen-mixer/printing/schemes/V4/Oxygen%20Mixer%20(Render%201).png" height="240">
  <img alt="Oxygen Mixer Print" src="./src/mechanics/parts/oxygen-mixer/printing/schemes/V4/Oxygen%20Mixer%20(Print%201).jpg" height="240">
</p>

### The "Machine Filter Box" (Both Directions)

<p>
  <img alt="Machine Filter Box Render" src="./src/mechanics/parts/machine-filter-box/printing/schemes/Archives/V1/Filter%20Box%20(Render%201).png" height="320">
  <img alt="Machine Filter Box Print" src="./src/mechanics/parts/machine-filter-box/printing/schemes/Archives/V1/Filter%20Box%20(Print%201).jpg" height="320">
</p>

### The "Patient Filter Box"

<p>
  <img alt="Patient Filter Box Render" src="./src/mechanics/parts/patient-filter-box/printing/schemes/V6/Filter%20Box%20(Mensurations).JPG" height="320">
  <img alt="Machine Filter Box Print" src="./src/mechanics/parts/patient-filter-box/printing/schemes/Archives/V5/Filter%20Box%20(Print%201).jpg" height="320">
</p>

### The "Pneumatic Connectors"

<p>
  <img alt="Pneumatic Connector Blower Render" src="./src/mechanics/parts/pneumatic-connectors/printing/schemes/V4/Blower%20V5/Pneumatic%20Connector%20Blower%20V5.png" height="240">
  <img alt="Pneumatic Connector O2 Render" src="./src/mechanics/parts/pneumatic-connectors/printing/schemes/V4/O2%20V3/Pneumatic%20Connector%20O2%20V3.png" height="240">
  <img alt="Pneumatic Connector No pressure Render" src="./src/mechanics/parts/pneumatic-connectors/printing/schemes/V4/Respiratory%20-%20No%20Pressure%20V3/Pneumatic%20Connector%20Respiratory%20No%20Pressure%20(Render%201).png" height="240">
  <img alt="Pneumatic Connector pressure Render" src="./src/mechanics/parts/pneumatic-connectors/printing/schemes/V4/Respiratory%20-%20Pressure%20V4/Pneumatic%20Connector%20Respiratory%20Pressure%20(Render%201).png" height="240">
  <img alt="Pneumatic Connector O2 Print" src="./src/mechanics/parts/pneumatic-connectors/printing/schemes/V4/O2%20V3/Pneumatic%20Connector%20O2%20V3%20Print.jpg" height="240">
  <img alt="Pneumatic Connector Blower Print" src="./src/mechanics/parts/pneumatic-connectors/printing/schemes/V4/Blower%20V5/Pneumatic%20Connector%20Blower%20V4%20Print.jpg" height="240">
  <img alt="Pneumatic Connector No pressure Print" src="./src/mechanics/parts/pneumatic-connectors/printing/schemes/V4/Respiratory%20-%20No%20Pressure%20V3/Pneumatic%20Connector%20Respiratory%20No%20Pressure%20(Print%201).jpg" height="240">
  <img alt="Pneumatic Connector No pressure Print" src="./src/mechanics/parts/pneumatic-connectors/printing/schemes/V4/Respiratory%20-%20Pressure%20V4/Pneumatic%20Connector%20Respiratory%20Pressure%20(Print%201).jpg" height="240">
</p>

### The "Fan Holder"

<p>
  <img alt="Fan Holder Floor Render" src="./src/mechanics/parts/fan-holder/printing/schemes/V2/Fan%20Holder%20V2%20(Floor)/Fan%20Holder%20Floor%20(Render%201).png" height="240">
  <img alt="Fan Holder Floor Print" src="./src/mechanics/parts/fan-holder/printing/schemes/V2/Fan%20Holder%20V2%20(Floor)/Fan%20Holder%20Floor%20(Print%201).jpg" height="240">
  <img alt="Fan Holder Wall Render" src="./src/mechanics/parts/fan-holder/printing/schemes/V2/Fan%20Holder%20V2%20(Wall)/Fan%20Holder%20Wall%20(Render%201).png" height="240">
  <img alt="Fan Holder Wall Print" src="./src/mechanics/parts/fan-holder/printing/schemes/V2/Fan%20Holder%20V2%20(Wall)/Fan%20Holder%20Wall%20(Print%201).jpg" height="240">
</p>

### The "Container"

<p>
  <img alt="Container Render" src="./src/mechanics/container/molding/schemes/V2/Container%20(Render%201).png" height="240">
  <img alt="Container Render" src="./src/mechanics/container/molding/schemes/V2/Container%20(Render%202).png" height="240">
  <img alt="Container Render" src="./src/mechanics/container/molding/schemes/V2/Container%20(Render%204).png" height="240">
  <img alt="Container Render" src="./src/mechanics/container/molding/schemes/V2/Container%20(Render%206).png" height="240">
  <img alt="Container Render" src="./src/mechanics/container/molding/schemes/V2/Container%20(Render%207).png" height="240">
  <img alt="Container Render" src="./src/mechanics/container/molding/schemes/V2/Container%20(Render%208).png" height="240">
  <img alt="Container Assembly" src="./src/mechanics/container/molding/schemes/V2/Container%20(Assembly%201).jpg" height="240">
</p>

## Electronics

### The "Motherboard"

<p>
  <img alt="Motherboard Picture" src="./src/electronics/motherboard/schemes/V2/Motherboard%20(Picture%201).jpg" height="240">
  <img alt="Motherboard Picture" src="./src/electronics/motherboard/schemes/V2/Motherboard%20(Picture%202).jpg" height="240">
  <img alt="Motherboard Picture" src="./src/electronics/motherboard/schemes/V2/Motherboard%20(Picture%203).jpg" height="240">
  <img alt="Motherboard Picture" src="./src/electronics/motherboard/schemes/V2/Motherboard%20(Picture%204).jpg" height="240">
  <img alt="Motherboard Picture" src="./src/electronics/motherboard/schemes/V2/Motherboard%20(Picture%205).jpg" height="240">
</p>
