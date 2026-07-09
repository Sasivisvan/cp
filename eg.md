Here's your complete 40-minute crash course, organized for fast recall. I'll hit every concept in the notes.

## 1. Distributed Systems Basics
- **Definition**: Multiple software components on multiple computers, but run as a single system. Computers can be close (LAN) or far (WAN).
- **Goal**: Make a network work as a single computer.
- **4 Models**:
  - **Minicomputer**: several minicomputers, each with terminals
  - **Workstation**: many workstations, supports process migration
  - **Workstation-Server**: adds dedicated servers (file/print) — cheap workstations, good resource sharing
  - **Processor-pool**: terminals + pool of processors on network

## 2. Classification of Distributed Computing
Tree: **Distributed Computing → Peer-to-Peer, Cluster, Utility, Jungle Computing**; Utility → **Grid, Cloud**

## 3. Cluster Computing
- Tightly/loosely connected computers acting as ONE entity, connected via fast **LAN**
- Root node (input/results) + slave nodes
- **Key trait: nodes must be HOMOGENEOUS**
- Benefits: cost-effective, processing speed, expandability, availability, flexibility, load balancing

## 4. Grid Computing
- Distributed architecture of computers working on a **joint task**, spread across geographies
- Subset of distributed computing — "virtual supercomputer"
- Task broken into fragments → processed in parallel → combined
- **3 machine types**: Control node/server, Provider/grid node, User
- **5 key components**: User Interface, Security, Scheduler, Data Management, Workload & Resource Management

### ⭐ Cluster vs Grid (HIGH-YIELD TABLE — likely to be asked)
| Cluster | Grid |
|---|---|
| Homogeneous nodes | Homogeneous or heterogeneous |
| Dedicated to same work | Contribute unused resources |
| Located close | Can be far apart |
| High-speed LAN | Low-speed bus/internet |
| Centralized topology | Distributed/decentralized topology |
| Central server scheduling | Mostly independent nodes |
| Centralized resource manager | Each node manages itself |
| Functions as single system | Each node autonomous, can opt out |

## 5. P2P Networks
- Two+ PCs share resources **without a separate server**
- Ad hoc (USB) or permanent infra
- Each computer = "peer"; access controlled via sharing permissions on individual machines

## 6. Utility Computing
- Resources provided **based on demand**, pay **exactly for usage** (not flat rate)
- Customer freed from hardware maintenance
- **Not all utility computing is cloud computing** (important line!)
- Adv: no buy hardware/software, single service company-wide, compatibility across depts
- Disadv: reliability risk, hacker target risk

## 7. Edge vs Fog Computing
- **Edge**: processes data at periphery/close to source, only results sent to data center
- **Fog**: decentralized layer BETWEEN cloud and edge devices; brings analytics closer to edge

### ⭐ Edge vs Fog Table (likely quiz question)
| Edge | Fog |
|---|---|
| Less scalable | Highly scalable |
| Billions of nodes | Millions of nodes |
| Far from cloud | Closer to cloud |
| Low bandwidth need | High bandwidth need |
| Higher operational cost | Lower operational cost |
| High privacy, low attacks | Higher attack probability |
| = IoT devices/client network | = extended layer of cloud |
| Low power consumption | High power consumption |

**IoT Data Layers pyramid**: Cloud (thousands, data centers) → Fog (millions, nodes) → Edge (billions, devices)

## 8. Cloud Computing Definitions
- **NIST**: model for ubiquitous, convenient, on-demand network access to shared configurable resources
- Composed of: **3 service models, 4 deployment models, 5 essential characteristics** (memorize these numbers!)

## 9. Cloud Delivery Models (IaaS/PaaS/SaaS) ⭐⭐⭐ Very likely tested
| Model | Control Given | Consumer Activity | Provider Activity |
|---|---|---|---|
| **IaaS** | Full administrative | Sets up/configures infra, installs software | Provisions physical processing/storage/network |
| **PaaS** | Limited administrative | Develops, tests, deploys apps | Pre-configures platform + infra |
| **SaaS** | Usage/config only | Uses & configures the service | Implements, manages, maintains everything |

- **IaaS**: raw IT resources (hardware, network, OS), virtualized; primary resource = **virtual server**
- **PaaS**: ready-to-use pre-configured environment; consumer spared admin burden; e.g., **Google App Engine**
- **SaaS**: software as shared service/product; very limited consumer control
- Can be **combined**: IaaS+PaaS+SaaS layered (PaaS runs on IaaS, SaaS runs on PaaS)

## 10. Cloud Deployment Models (4 types)
- **Public**: third-party owned, publicly accessible (Google, Amazon, Microsoft etc.)
- **Community**: like public but limited to specific community of consumers
- **Private**: owned by single organization
- **Hybrid**: combination of 2+ deployment models (e.g., sensitive data private + rest public)
- Variants: **Virtual Private Cloud** (dedicated/hosted cloud), **Inter-Cloud** (2+ interconnected clouds)

## 11. Cloud Characteristics (6 — note NIST officially has 5, Resiliency excluded by NIST) ⭐
1. **On-demand usage** – self-provision resources
2. **Ubiquitous access** – widely accessible via many devices/protocols
3. **Multitenancy** – one instance serves multiple isolated tenants (resource pooling)
4. **Elasticity** – automated scaling up/down
5. **Measured usage** – tracks usage for billing/monitoring
6. **Resiliency** – redundant IT resources across locations for failover (NOT in NIST's official 5)

## 12. Benefits vs Risks
**Pros**: speed, accessibility, ease of use/manage/maintain, reliability, mobility, less hardware dependency, cost-effective, security
**Cons**: security & privacy, interoperability, portability, **vendor lock-in**, quality of service, reliability, compliance, legal issues, cost, computing performance

## 13. Cloud Native Applications
- Built, tested, deployed, managed **end-to-end in the cloud**
- **4 components**: **DevOps**, **Continuous Delivery**, **Microservices**, **Containers**
- Cloud-native (designed FOR cloud) vs Cloud-based (uses cloud but not optimized for it)
- **Monolithic** (single block: client→business logic→data access→DB) vs **Microservices** (small independent services, each own DB)
- Benefits: cost-effective, independently scalable, portable (avoids vendor lock-in), reliable, easy to manage, visibility

## 14. MEAN vs MERN Stack ⭐
- **MEAN** = MongoDB, Express, **Angular**, Node
- **MERN** = MongoDB, Express, **React**, Node
- MongoDB = database, Express = Node.js web framework, Node = JS server

| | MEAN | MERN |
|---|---|---|
| Data flow | Bidirectional | Unidirectional |
| DOM | Regular DOM | Virtual DOM |
| Learning curve | Steeper (MVC, TypeScript) | Easier |
| Examples | PayPal, Upwork, Forbes | Facebook, Netflix, Discord |

---

**Quick memory hooks before your quiz:**
- Cluster = same hardware, close, one system. Grid = different hardware possible, far apart, contributes spare resources.
- IaaS = infrastructure/virtual server; PaaS = ready platform; SaaS = full software product.
- Edge = at the device; Fog = layer between edge and cloud.
- 3 service models / 4 deployment models / 5(NIST)-6(with resiliency) characteristics.
- MEAN=Angular, MERN=React.

Good luck on your quiz!
